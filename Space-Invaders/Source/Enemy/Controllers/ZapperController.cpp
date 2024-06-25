#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	namespace Controller
	{
		using namespace Global;
		ZapperController::ZapperController(EnemyType type) : EnemyController(type) 
		{
			
		}
		
		ZapperController::~ZapperController()
		{
		}
		void ZapperController::Initialize()
		{
			EnemyController::Initialize();

		}

		void ZapperController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case MovementDirection::RIGHT:
			{
				MoveRight();
				break;
			}
			case MovementDirection::LEFT:
			{
				MoveLeft();
				break;
			}
			case MovementDirection::DOWN:
			{
				MoveDown();
				break;
			}

			}
		}

		void ZapperController::MoveDown()
		{


			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.y -= verticalTravelDistance * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.y >= enemyModel->GetReferencePosition().y + verticalTravelDistance)
			{
				if (enemyModel->GetEnemyPosition().x <= enemyModel->LeftMostPosition.x)
				{
					enemyModel->SetMovementDirection(MovementDirection::RIGHT);
				}
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);

			}
		}

		void ZapperController::MoveRight()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.x += enemyModel->enemyMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x >= enemyModel->RightMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::DOWN);
				enemyModel->SetReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}
		
		void ZapperController::MoveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.x -= enemyModel->enemyMovementSpeed;

			if (currentPosition.x <= enemyModel->LeftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::DOWN);
				enemyModel->SetReferencePosition(currentPosition);

			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);

			}
		}
	}
}