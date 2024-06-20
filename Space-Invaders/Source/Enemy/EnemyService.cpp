#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Time/TimeService.h"
#include <vector>


namespace Enemy
{
	using namespace Global;
	using namespace Time;

	Enemy::EnemyService::EnemyService()
	{
		for (int i = 0;i < enemyList.size(); i++)
		{
			enemyList[i] = nullptr;
		}
		
	}

	Enemy::EnemyService::~EnemyService()
	{
		Destroy();
	}



	void Enemy::EnemyService::Destroy()
	{

		for (int i = 0;i < enemyList.size(); i++)
		{
			delete(enemyList[i]);
			enemyList[i] = nullptr;

		}

	}

	void EnemyService::Initialize()
	{
		spawnTimer = spawnIntervel;
		SpawnEnemy();
	}

	void EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = new EnemyController();
		enemyController->Initialize();
		enemyList.push_back(enemyController);

	}

	void EnemyService::Update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0;i < enemyList.size(); i++)
		{
			enemyList[i]->Update();

		}
	}
	void EnemyService::updateSpawnTimer()
	{
		spawnTimer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawnTimer > spawnIntervel)
		{
			SpawnEnemy();
			spawnTimer = 0.f;
		}
	}

	void EnemyService::Render()
	{

		for (int i = 0;i < enemyList.size(); i++)
		{
			enemyList[i]->Render();

		}
	}



}