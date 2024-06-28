#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Bullet/BulletConfig.h"



namespace Enemy
{

	namespace Controller
	{
		using namespace Global;
		
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type)
		{
		}

		ThunderSnakeController::~ThunderSnakeController()
		{
		}

		void ThunderSnakeController::Initialize()
		{
			EnemyController::Initialize();
		}

		void ThunderSnakeController::FireBullet()
		{

			ServiceLocator::GetInstance()->GetBulletServices()->SpawnBullet(Bullet::BulletType::TORPEDO,
				enemyModel->GetEnemyPosition() + enemyModel->barrelPositionOffset,
				Bullet::MovementDirection::DOWN);

		}
		void ThunderSnakeController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
				
			case MovementDirection::RIGHT:
			{
				MoveRight();
				break;
			}
	
			case MovementDirection::DIAGONAL_LEFT:
			{
				MoveDiagonalLeft();
				break;
			}
			case MovementDirection::DIAGONAL_RIGHT:
			{
				MoveDiagonalRight();
				break;
			}

			}
		}

		void ThunderSnakeController::MoveRight()
		{
			
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.x += verticalspeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			
				if (enemyModel->GetEnemyPosition().x >= enemyModel->RightMostPosition.x)
				{
					
					enemyModel->SetMovementDirection(MovementDirection::DIAGONAL_LEFT);
				}
				else
				{
					enemyModel->SetEnemyPosition(currentPosition);
				}
			
		}

		void ThunderSnakeController::MoveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.x -= verticalspeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

         
			if (currentPosition.x <= enemyModel->LeftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::DIAGONAL_RIGHT);
				enemyModel->SetReferencePosition(currentPosition);

			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);

			}
		}

		void ThunderSnakeController::MoveDiagonalLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.x -= verticalspeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			currentPosition.y += horizontalspeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			
				if (enemyModel->GetEnemyPosition().x <= enemyModel->LeftMostPosition.x)
				{
					enemyModel->SetMovementDirection(MovementDirection::RIGHT);

				}
				else
				{
					enemyModel->SetEnemyPosition(currentPosition);

				}
			
		}

		void ThunderSnakeController::MoveDiagonalRight()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.x += verticalspeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			currentPosition.y += horizontalspeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			
				if (enemyModel->GetEnemyPosition().x <= enemyModel->LeftMostPosition.x)
				{
					enemyModel->SetMovementDirection(MovementDirection::LEFT);

				}
				else
				{
					enemyModel->SetEnemyPosition(currentPosition);

				}
			

		}
	}
}
