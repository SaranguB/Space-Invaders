#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"

#include <vector>


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

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

	EnemyController* EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = createEnemy(GetRandomEnemyType());

		enemyController->Initialize();
		enemyList.push_back(enemyController);

		return enemyController;
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemyType)
	{
		switch (enemyType)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case::Enemy::EnemyType::SUBZERO:
			return new SubZeroController(Enemy::EnemyType::SUBZERO);

			/*case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);*/

			/*case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);*/
		}


	}
	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 2;
		return static_cast<Enemy::EnemyType>(randomType);
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

	void EnemyService::DestroyEnemy(EnemyController* enemyController)
	{
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());
		delete(enemyController);
	}



}