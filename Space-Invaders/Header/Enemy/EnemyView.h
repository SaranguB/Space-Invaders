#pragma once
#include<SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;
	class EnemyModel;

	class EnemyView
	{
	private:
		EnemyController* enemyController;
		

		const float enemySpriteHeight = 60.f;
		const float enemySpriteWidth = 60.f;


		EnemyModel* enemyModel;
		UI::UIElement::ImageView* enemyImage;

		void InitializeEnemySprite();
		void Destroy();
		void CreateUIElement();
		sf::String GetEnemyTexturePath();


	public:
		EnemyView();
		~EnemyView();

		void Initialize(EnemyController* controller);
		void update();
		void Render();

		const sf::Sprite& GetEnemySprite();

	};
}
