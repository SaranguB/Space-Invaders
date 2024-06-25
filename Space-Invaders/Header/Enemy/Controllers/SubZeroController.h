#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	class EnemyModel;
	namespace Controller
	{
		class SubZeroController : public EnemyController
		{
		private:

			float speed = 100.0f;
			EnemyModel* enemyModel;
			void Move() override;
			void MoveDown();

		public:
			SubZeroController(EnemyType type);
			~SubZeroController();

				void Initialize() override;

		};
	}
}