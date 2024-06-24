#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;
	class EnemyModel;

	class EnemyView
	{
	private:
		EnemyController* enemyController;
		sf::String zapperTexturePath ="assets/textures/zapper.png";
		sf::String subzeroTexturePath = "assets/textures/subzero.png";

		const float enemySpriteHeight = 60.f;
		const float enemySpriteWidth = 60.f;


		sf::RenderWindow* gameWindow;
		sf::Texture enemyTexture;
		sf::Sprite enemySprite;
		EnemyModel* enemyModel;

		void InitializeEnemySprite(EnemyType type);
		void ScaleEnemySprite();


	public:
		EnemyView();
		~EnemyView();

		void Initialize(EnemyController* controller);
		void update();
		void Render();

	};
}
