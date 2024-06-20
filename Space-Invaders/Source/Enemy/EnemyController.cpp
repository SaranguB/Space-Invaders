#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
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
	}

	void Enemy::EnemyController::Render()
	{
		enemyView->Render();
	}
	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}
}
