#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class LaserBulletController : public BulletController
		{

		public:
			LaserBulletController(BulletType type);
			~LaserBulletController() ;

			void Initialize(sf::Vector2f position, MovementDirection direction);

		};
	}
}
