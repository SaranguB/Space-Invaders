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

			const float verticalSpeed = 200.f;
			const float horizontalSpeed = 50.f;
			void FireBullet() override;



			ThunderSnakeController(EnemyType type);
			~ThunderSnakeController();

			void Initialize() override;
		};
	}
}
