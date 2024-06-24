#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class ZapperController : public EnemyController
		{
		private:

			const float verticalTravelDistance = 100.0f;

			void Move() override;
			void MoveLeft();
			void MoveRight();
			void MoveDown();

		public:
			ZapperController();
			~ZapperController();

			void Initialize() override;
		};
	}
}