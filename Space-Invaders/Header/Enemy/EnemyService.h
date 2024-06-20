#pragma once
#include<vector>

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{

	private:

		std::vector<EnemyController*> enemyList;

		const float spawnIntervel = 3.f;
		float spawnTimer;

		void updateSpawnTimer();
		void processEnemySpawn();
		void Destroy();

		
	public:
		

		EnemyService();
		~EnemyService();


		void Initialize();
		void Update();
		void Render();

		void SpawnEnemy();
	};
}
