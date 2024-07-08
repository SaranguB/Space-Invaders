#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/FrostBulletController .h"
#include "../../Header/Bullet/Controllers/LaserBulletController .h"
#include "../../header/Collision/ICollider.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;
	using namespace Global;
	using namespace Collision;

	BulletService::BulletService()
	{
	}
	BulletService::~BulletService()
	{
		Destroy();
	}

	void BulletService::Initialize()
	{
		bulletList.clear();
		flaggedBulletList.clear();
	}

	void BulletService::Update()
	{
		for (int i = 0;i < bulletList.size();i++)
		{
			bulletList[i]->Update();
		}
		DestroyFlaggedBullet();
	}

	void BulletService::Render()
	{
		for (int i = 0;i < bulletList.size();i++)
		{
			bulletList[i]->Render();
		}
	}


	BulletController* BulletService::SpawnBullet(BulletType bulletType, sf::Vector2f position,
		MovementDirection direction, Entity::EntityType ownerType)
	{
		BulletController* bulletController = CreateBullet(bulletType, ownerType);
		bulletController->Initialize(position, direction);

		ServiceLocator::GetInstance()->GetCollisionService()->
			AddCollider(dynamic_cast<ICollider*>(bulletController));

		bulletList.push_back(bulletController);
		return bulletController;
	}

	void BulletService::DestroyBullet(BulletController* bulletController)
	{
		if (std::find(flaggedBulletList.begin(), flaggedBulletList.end(),
			bulletController) == flaggedBulletList.end())
		{
			flaggedBulletList.push_back(bulletController);

			bulletList.erase(std::remove(bulletList.begin(),
				bulletList.end(), bulletController), bulletList.end());
		}
	}

	bool BulletService::IsValidBullet(int indexI, std::vector<Projectile::IProjectile*>& bullet_list)
	{
		return indexI >= 0 && indexI < bulletList.size() && bulletList[indexI] != nullptr;
	}

	void BulletService::DestroyFlaggedBullet()
	{
		for (int i = 0;i < flaggedBulletList.size();i++)
		{
			if (!IsValidBullet(i, flaggedBulletList))continue;

			ServiceLocator::GetInstance()->GetCollisionService()
				->RemoveCollider(dynamic_cast<ICollider*>(flaggedBulletList[i]));
			delete(flaggedBulletList[i]);
		}
		flaggedBulletList.clear();
	}

	void BulletService::Reset()
	{
		Destroy();
	}

	void BulletService::Destroy()
	{
		for (int i = 0;i < bulletList.size();i++)
		{
			if (!IsValidBullet(i, bulletList))continue;

			ServiceLocator::GetInstance()->GetCollisionService()
				->RemoveCollider(dynamic_cast<ICollider*>(bulletList[i]));

			delete(bulletList[i]);
		}
		bulletList.clear();
	}

	BulletController* BulletService::CreateBullet(BulletType bulletType, Entity::EntityType ownerType)
	{

		switch (bulletType)
		{
		case BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET, ownerType);

		case BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, ownerType);

		case BulletType::TORPEDO:
			return new TorpedoeController(Bullet::BulletType::TORPEDO, ownerType);
		}

	}



}
