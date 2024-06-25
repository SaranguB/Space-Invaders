#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	class EnemyModel;
	namespace Controller
	{

		class ZapperController : public EnemyController
		{
		private:
			EnemyModel* enemyModel;
			const float verticalTravelDistance = 100.0f;

			void Move() override;
			void MoveLeft();
			void MoveRight();
			void MoveDown();

		public:
			ZapperController(EnemyType type);
			~ZapperController();

			void Initialize() override;
		};
	}
}