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
			void Move() override;
			void MoveDown();
			const float subZeroRateofFire = 2;

		public:
			SubZeroController(EnemyType type);
			~SubZeroController();

				void Initialize() override;
				void FireBullet() override;


		};
	}
}