#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"

#include <vector>


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;
	using namespace Collision;

	Enemy::EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		for (int i = 0;i < enemyList.size(); i++)
		{
			enemyList[i] = nullptr;
		}

	}

	Enemy::EnemyService::~EnemyService()
	{
		Destroy();
	}



	void EnemyService::DestroyFlaggedEnemy()
	{
		for (int i = 0;i < flaggedEnemyList.size();i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()
				->RemoveCollider(dynamic_cast<ICollider*>(flaggedEnemyList[i]));
			delete(flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}

	void Enemy::EnemyService::Destroy()
	{

		for (int i = 0;i < enemyList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()
				->RemoveCollider(dynamic_cast<ICollider*>(enemyList[i]));
			delete(enemyList[i]);

		}
		enemyList.clear();
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

		ServiceLocator::GetInstance()->GetCollisionService()
			->AddCollider(dynamic_cast<ICollider*>(enemyController));
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

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);


		}


	}
	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 4;
		return static_cast<Enemy::EnemyType>(randomType);
	}


	void EnemyService::Update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (EnemyController* enemy : enemyList)
		{
			enemy->Update();

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

	void EnemyService::Reset()
	{
		Destroy();
		spawnTimer = 0.0f;
	}

	void EnemyService::DestroyEnemy(EnemyController* enemyController)
	{
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());
		delete(enemyController);
	}



}