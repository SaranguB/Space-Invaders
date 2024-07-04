#pragma once
#include<vector>
#include "../../Header/Entity/EntityConfig.h"

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{

	private:

		std::vector<EnemyController*> enemyList;

		const float spawnIntervel = 2.f;
		float spawnTimer;

		EnemyController* enemyController;

		void updateSpawnTimer();
		void processEnemySpawn();
		void Destroy();

		EnemyType GetRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemyType);

		
	public:
		

		EnemyService();
		~EnemyService();


		void Initialize();
		void Update();
		void Render();

		void DestroyEnemy(EnemyController* enemyController);

		EnemyController* SpawnEnemy(Entity::EntityType entityType);
	};
}
