#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
	class BulletController;
	enum class BulletType;

	class BulletView

	{

	private:
		float bulletSpriteWidth = 18.f;
		float bulletSpriteHeight = 18.f;

		BulletController* bulletController;

		sf::RenderWindow* gameWindow;
		sf::Texture bulletTexture;
		sf::Sprite bulletSprite;

		void InitializeImage(BulletType type);
		void ScaleImage();

	public:
		BulletView();
		~BulletView();

		void Initialize(BulletController* controller);
		void Update();
		void Render();

	};
}