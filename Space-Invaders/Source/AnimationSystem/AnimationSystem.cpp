#include "../../Header/AnimationSystem/AnimationSystem.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Animation
{
	using namespace UI::UIElement;
	using namespace Global;

	AnimationSystem::AnimationSystem(AnimationSystemConfig config)
	{
		animationSystemConfig = config;
		CreateUIElement();
	}

	AnimationSystem::~AnimationSystem()
	{
		delete(animationImage);
	}

	void AnimationSystem::CreateUIElement()
	{
		animationImage = new ImageView();
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

			animationImage->SetTextureRect(sf::IntRect(
				currentFrame* animationSystemConfig.tileWidth,
				0, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight));
		}
		animationImage->Update();
	}

	void AnimationSystem::Render()
	{
		animationImage->Render();
	}

	void AnimationSystem::Destory()
	{
		ServiceLocator::GetInstance()->GetAnimationService()->DestroyAnimationSystem(this);
	}
}