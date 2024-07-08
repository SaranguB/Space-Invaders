#pragma 
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerup/PowerupConfig.h"


namespace Enemy
{
	namespace Controller
	{
		class UFOController : public EnemyController
		{
		private:

			void Move() override;
			void MoveLeft();
			void MoveRight();

			void FireBullet() override;		
			Powerup::PowerupType GetRandomPowerupType();

		public:
			UFOController(EnemyType type);
			~UFOController();
			float verticalSpeed = 50.f;

			void Initialize() override;
			void OnCollision(ICollider* otherCollider) override;
			
		};
	}
}