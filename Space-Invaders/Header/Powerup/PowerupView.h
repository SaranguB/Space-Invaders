#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Powerup
{
	enum class PowerupType;
	class PowerupController;
	class PowerupView
		
	{
	private:

		float spriteWidth = 30.f;
		float spriteHeight = 30.f;

		PowerupController* powerupController;
		UI::UIElement::ImageView* powerupImage;

		sf::RenderWindow* gameWindow;

		void CreateUIElement();
		void InitializeImage();
		sf::String GetPowerupTexturePath();
		void Destroy();

	
	public:

		PowerupView();
		~PowerupView();

		void Initialize(PowerupController* Controller);
		void Update();
		void Render();

		const sf::Sprite& GetPowerupSprite();
	};
}
