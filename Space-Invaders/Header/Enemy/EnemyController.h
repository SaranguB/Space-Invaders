#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

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
		 EnemyController(EnemyType type, Entity::EntityType entityType);
		virtual ~EnemyController();


		virtual void Initialize();
		void Update();
		void Render();
		virtual void Move() = 0;
		

		sf::Vector2f GetEnemyPosition();


		EnemyType GetEnemyType();
		EnemyState GetEnemyState();

		Entity::EntityType GetEntityType();
	};
}
