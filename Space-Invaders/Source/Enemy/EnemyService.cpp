#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"


namespace Enemy
{
	using namespace Global;
	Enemy::EnemyService::EnemyService()
	{
		enemyController = nullptr;
	}

	Enemy::EnemyService::~EnemyService()
	{
		Destroy();
	}

	void Enemy::EnemyService::Destroy()
	{
		delete(enemyController);
		enemyController = nullptr;
	}

	void EnemyService::Initialize()
	{
		SpawnEnemy();
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		enemyController = new EnemyController();
		enemyController->Initialize();
		return enemyController;

	}

	void EnemyService::Update()
	{
		enemyController->Update();
	}

	void EnemyService::Render()
	{
		enemyController->Render();
	}



}