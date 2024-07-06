#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:

		std::vector <Projectile::IProjectile*> bulletList;
		std::vector <Projectile::IProjectile*> flaggedBulletList;

		BulletController* CreateBullet(BulletType bulletType, Entity::EntityType ownerType);

		void Destroy();
		bool IsValidBullet(int indexI, std::vector<Projectile::IProjectile*>& bullet_list);
		void DestroyFlaggedBullet();

	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();
		void Reset();

		BulletController* SpawnBullet(BulletType bulletType, sf::Vector2f position, 
			MovementDirection direction, Entity::EntityType ownerType);

		void DestroyBullet(BulletController* bulletController);

	};
}