#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class SubZeroController : public EnemyController
		{
		private:

			float speed = 100.0f;

			void Move() override;
			void MoveDown();

		public:
			SubZeroController();
			~SubZeroController();

				void Initialize() override;

		};
	}
}