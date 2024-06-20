#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	Enemy::EnemyController::EnemyController()
	{
		enemyView = new EnemyView();
		enemyModel = new EnemyModel();
	}

	Enemy::EnemyController::~EnemyController()
	{
		delete(enemyView);
		delete(enemyModel);

	}

	void Enemy::EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyView->Initialize(this);
	}

	void Enemy::EnemyController::Update()
	{
		enemyView->update();
		Move();
	}

	void Enemy::EnemyController::Render()
	{
		enemyView->Render();
	}
	void EnemyController::Move()
	{
		switch (enemyModel->GetMovementDirection())
		{

		case MovementDirection::LEFT:
			MoveLeft();
			break;

		case MovementDirection::RIGHT:
			MoveRight();
			break;

		case MovementDirection::DOWN:
			MoveDown();
			break;

		}
	}

	void EnemyController::MoveRight()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
		currentPosition.x += enemyModel->enemyMovementSpeed * 
			ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.x >= enemyModel->RightMostPosition.x)
		{
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			enemyModel->SetReferencePosition(currentPosition);
		}
		else enemyModel->SetEnemyPosition(currentPosition);
	}

	

	void EnemyController::MoveLeft()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
		currentPosition.x -= enemyModel->enemyMovementSpeed *
			ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.x <= enemyModel->LeftMostPosition.x)
		{
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			enemyModel->SetReferencePosition(currentPosition);
		}
		else enemyModel->SetEnemyPosition(currentPosition);
	}

	void EnemyController::MoveDown()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
		currentPosition.y += enemyModel->enemyMovementSpeed *
			ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		if (currentPosition.y >= enemyModel->GetReferencePosition().y + enemyModel->verticalTravelDistance)
		{
			if (enemyModel->GetReferencePosition().x <= enemyModel->LeftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			}
			else 
			{
				enemyModel->SetMovementDirection(MovementDirection::LEFT);

			}
		}
		else
		{
			enemyModel->SetEnemyPosition(currentPosition);
		}
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}
}
