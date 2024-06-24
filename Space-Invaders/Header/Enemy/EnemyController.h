#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
	private:
		EnemyView* enemyView;
		EnemyModel* enemyModel;

	public:
		 EnemyController();
		virtual ~EnemyController();


		virtual void Initialize();
		void Update();
		void Render();
		virtual void Move() = 0;
		

		sf::Vector2f GetEnemyPosition();
		
	};
}
