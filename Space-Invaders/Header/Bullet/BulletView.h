#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

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


		void InitializeImage();

		void CreateUIElement();
		void Destroy();
		sf::String GetBulletTexturePath();
		UI::UIElement::ImageView* bulletImage;

	public:
		BulletView();
		~BulletView();

		void Initialize(BulletController* controller);
		void Update();
		void Render();

	};
}