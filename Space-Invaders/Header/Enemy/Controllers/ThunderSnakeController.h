#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class ThunderSnakeController : public EnemyController
		{
		private:
			
			void Move() override;
			
			void MoveRight();
			void MoveLeft();

			void MoveDiagonalLeft();
			void MoveDiagonalRight();


		public:

			const float verticalspeed = 200.f;
			const float horizontalspeed = 50.f;



			ThunderSnakeController(EnemyType type);
			~ThunderSnakeController();

			void Initialize() override;
		};
	}
}
