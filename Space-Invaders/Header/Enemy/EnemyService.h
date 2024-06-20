#pragma once

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{

	private:
		void Destroy();
		EnemyController* enemyController;

	public:
		EnemyService();
		~EnemyService();


		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy();
	};
}
