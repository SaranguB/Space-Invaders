#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"



namespace Enemy
{
	namespace Controller
	{
		using namespace Global;
		using namespace Bullet;

		SubZeroController::SubZeroController(EnemyType type) : EnemyController(type) {}
		

		SubZeroController::~SubZeroController()
		{

		}
		void SubZeroController::Initialize()
		{
			//printf("hi");
			EnemyController::Initialize();
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			rateOfFire = subZeroRateofFire;

		}

		void SubZeroController::FireBullet()
		{
			ServiceLocator::GetInstance()->GetBulletServices()->SpawnBullet(BulletType::FROST_BULLET,
				enemyModel->GetEnemyPosition() + enemyModel->barrelPositionOffset,
				Bullet::MovementDirection::DOWN);
		}

		void SubZeroController::Move()
		{
			if (enemyModel->GetMovementDirection() == MovementDirection::DOWN)
			{
				MoveDown();
			}
			 
		}
		void SubZeroController::MoveDown()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.y += speed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			enemyModel->SetEnemyPosition(currentPosition);
		}

	}
	
}


