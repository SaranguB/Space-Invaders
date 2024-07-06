#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"


namespace Enemy
{
	namespace Controller
	{
		using namespace Global;
		using namespace Bullet;
		UFOController::UFOController(EnemyType type) : EnemyController(type)
		{
		}

		UFOController::~UFOController()
		{
		}

		void UFOController::Initialize()
		{
			EnemyController::Initialize();
		}

		void UFOController::OnCollision(ICollider* otherCollider)
		{
			EnemyController::OnCollision(otherCollider);

			BulletController* bulletCOntroller = dynamic_cast<BulletController*>(otherCollider);
			if (bulletCOntroller && bulletCOntroller->GetOwnerEntityType() != Entity::EntityType::ENEMY)
			{
				ServiceLocator::GetInstance()->GetPowerupService()
					->SpawnPowerup(GetRandomPowerupType(), enemyModel->GetEnemyPosition());

				return;
			}

		}

		void UFOController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case MovementDirection::RIGHT:
				MoveRight();
				break;
			case MovementDirection::LEFT:
				MoveLeft();
				break;
			}
		}

		void UFOController::MoveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.x -= verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();


			if (currentPosition.x <= enemyModel->LeftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT);
				enemyModel->SetReferencePosition(currentPosition);

			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);

			}
		}

		void UFOController::MoveRight()
		{

			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.x += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();


			if (enemyModel->GetEnemyPosition().x >= enemyModel->RightMostPosition.x)
			{

				enemyModel->SetMovementDirection(MovementDirection::LEFT);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}

		void UFOController::FireBullet()
		{
		}

		Powerup::PowerupType UFOController::GetRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);

			return static_cast<Powerup::PowerupType>(random_value);
		}
	}
}