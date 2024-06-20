#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;

	class EnemyView
	{
	private:
		EnemyController* enemyController;
		sf::String enemyTexturePath ="assets/textures/zapper.png";

		const float enemySpriteHeight = 60.f;
		const float enemySpriteWidth = 60.f;

		sf::RenderWindow* gameWindow;
		sf::Texture enemyTexture;
		sf::Sprite enemySprite;

		void InitializeEnemySprite();
		void ScaleEnemySprite();


	public:
		EnemyView();
		~EnemyView();

		void Initialize(EnemyController* controller);
		void update();
		void Render();

	};
}
