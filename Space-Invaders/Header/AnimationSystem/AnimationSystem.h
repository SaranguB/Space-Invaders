#pragma once
#include <SFML/Graphics.hpp>
#include "AnimationSystemConfig.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Animation
{
	class AnimationSystem
	{
	private:
		AnimationSystemConfig animationSystemConfig;
		sf::Vector2f animationPosition;
		UI::UIElement::ImageView* animationImage;

		void CreateUIElement();
		void InitializeImage();

		sf::Clock clock;
		sf::Time frameTime;

		int currentFrame;

	public:

		AnimationSystem(AnimationSystemConfig config);
		~AnimationSystem();


		void Initialize(sf::Vector2f position);
		void Update();
		void Render();

		void Destory();

	};
}
