#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Enemy
{
	class EnemyView;
	class EnemyModel;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController: public Collision::ICollider
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
			void Destroy();


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

		const sf::Sprite& GetColliderSprite() override;
		virtual void OnCollision(ICollider* otherCollider) override;


	};
}
