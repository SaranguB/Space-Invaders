#pragma once
#include<vector>
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Projectile/IProjectile.h"

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{

	private:

		std::vector<EnemyController*> enemyList;
		std::vector <EnemyController*> flaggedEnemyList;
		 
		const float spawnIntervel = 2.f;
		float spawnTimer;

		EnemyController* enemyController;

		void updateSpawnTimer();
		void processEnemySpawn();
		

		EnemyType GetRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemyType);

		void DestroyFlaggedEnemy();
		void Destroy();

	public:
		

		EnemyService();
		~EnemyService();


		void Initialize();
		void Update();
		void Render();

		void Reset();

		void DestroyEnemy(EnemyController* enemyController);

		EnemyController* SpawnEnemy();
	};
}
