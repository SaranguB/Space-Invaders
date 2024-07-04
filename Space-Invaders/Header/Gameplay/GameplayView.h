#pragma once
#include<SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Gameplay
{
	class GameplayView
	{
	private:


		UI::UIElement::ImageView* gameplayImage;
		sf::RenderWindow* gameWindow;

		void InitializeBackgroundSprite();
		void CreateUIElment();
		void Destroy();

	public:

		GameplayView();
		~GameplayView();

		void Initialize();
		void Update();
		void Render();

	};
}
