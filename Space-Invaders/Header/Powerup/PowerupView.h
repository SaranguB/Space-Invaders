#pragma once
#include <SFML/Graphics.hpp>

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

		sf::RenderWindow* gameWindow;

		sf::Texture powerupTexture;
		sf::Sprite powerupSprite;

		void InitializeImage(PowerupType type);
		void ScaleImage();
	
	public:

		PowerupView();
		~PowerupView();

		void Initialize(PowerupController* Controller);
		void Update();
		void Render();
	};
}
