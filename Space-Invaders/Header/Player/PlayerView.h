#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:

		PlayerController* playerController;

		sf::Texture playerTexture;
		sf::Sprite playerSprite;

		const float playerSpriteWidth = 60.f;
		const float playerSpriteHeight = 60.f;

		sf::RenderWindow* gameWindow;

		UI::UIElement::ImageView* playerImage;


		void CreateUIElement();
		sf::String GetPlayerTexturePath();
		void Destroy();
		void InitializePlayerSprite();


	public:
		PlayerView();
		~PlayerView();

		void Initialize(PlayerController* controller);
		void Update();
		void Render();


	};
}