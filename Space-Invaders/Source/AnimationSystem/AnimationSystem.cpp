#include "../../Header/AnimationSystem/AnimationSystem.h"
#include "../../Header/Global/Config.h"

namespace Animation
{
	using namespace UI::UIElement;
	using namespace Global;

	AnimationSystem::AnimationSystem(AnimationSystemConfig config)
	{
		animationSystemConfig = config;
		CreateUIElement();
	}

	void AnimationSystem::CreateUIElement()
	{
		animationImage = new ImageView();
	}

	AnimationSystem::~AnimationSystem()
	{
		delete(animationImage);
	}

	void AnimationSystem::Initialize(sf::Vector2f position)
	{
		animationPosition = position;
		currentFrame = 0;
		frameTime = sf::seconds(animationSystemConfig.frameDuration);
		InitializeImage();
	}

	void AnimationSystem::InitializeImage()
	{
		animationImage->Initialize(Config::explosion_texture_path, 0, 0, animationPosition);
		animationImage->SetTextureRect(sf::IntRect(0, 0,
			animationSystemConfig.tileWidth, animationSystemConfig.tileHeight));

		animationImage->SetScale(animationSystemConfig.spriteSheetWidth,
			animationSystemConfig.spriteSheetHeight,
			animationSystemConfig.tileWidth, animationSystemConfig.tileHeight);
	}

	void AnimationSystem::Update()
	{
		if (clock.getElapsedTime() >= frameTime)
		{
			if (currentFrame + 1 >= animationSystemConfig.numberOfAnimationFrame)
				Destory();

			currentFrame = (currentFrame + 1) % animationSystemConfig.numberOfAnimationFrame;
			clock.restart();

			animationImage->SetTextureRect(currentFrame* animationSystemConfig.tileWidth,
				0, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight);
		}
	}

	void AnimationSystem::Render()
	{
	}
	void AnimationSystem::Destory()
	{
	}
}