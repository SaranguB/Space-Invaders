#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	using namespace Global;



	Enemy::EnemyController::EnemyController(EnemyType type)
	{
		//printf("hi");
	
		enemyView = new EnemyView();
		enemyModel = new EnemyModel(type);
		
	}

	Enemy::EnemyController::~EnemyController()
	{
		delete(enemyView);
		delete(enemyModel);

	}

	void Enemy::EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyModel->SetEnemyPosition(getRandomInitialPosition());
		enemyView->Initialize(this);

	}

	void Enemy::EnemyController::Update()
	{
		enemyView->update();
		Move();
		handleOutOfBounds();

	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{

		float xOffsetDistance = (std::rand() % static_cast<int>(enemyModel->RightMostPosition.x -
			enemyModel->LeftMostPosition.x));

		float xPosition = enemyModel->LeftMostPosition.x + xOffsetDistance;

		float yPosition = enemyModel->LeftMostPosition.y;

		return sf::Vector2f(xPosition, yPosition);


	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = GetEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (enemyPosition.x< 0 || enemyPosition.x >windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y>windowSize.y)
		{
			ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
		}
	}

	void Enemy::EnemyController::Render()
	{
		enemyView->Render();
	}
	void EnemyController::Move()
	{
		/*switch (enemyModel->GetMovementDirection())
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

		}*/
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}

	EnemyType EnemyController::GetEnemyType()
	{
		return enemyModel->GetEnemyType();
	}

	EnemyState EnemyController::GetEnemyState()
	{
		return enemyModel->GetEnemyState();
	}

}
