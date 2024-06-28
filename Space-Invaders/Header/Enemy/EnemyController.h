#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController
	{
	protected:
		EnemyView* enemyView;
		EnemyModel* enemyModel;

		sf::Vector2f getRandomInitialPosition();
			void handleOutOfBounds();

			float rateOfFire = 3.0f;
			float elapsedFireDuration = 0.f;

			void UpdateFireTime();
			void ProcessBulletFire();
			virtual void FireBullet() = 0;

	public:
		 EnemyController(EnemyType type);
		virtual ~EnemyController();


		virtual void Initialize();
		void Update();
		void Render();
		virtual void Move() = 0;
		

		sf::Vector2f GetEnemyPosition();


		EnemyType GetEnemyType();
		EnemyState GetEnemyState();
	};
}
