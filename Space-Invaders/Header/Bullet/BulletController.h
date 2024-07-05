#pragma once
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Bullet
{
	enum class BulletType;
	class BulletView;
	class BulletModel;

	class BulletController : public Projectile::IProjectile, public::Collision::ICollider
	{
	protected:

		BulletView* bulletView;
		BulletModel* bulletModel;

		void UpdateProjectilePosition() override;

		void MoveUP();
		void MoveDown();

		void HandleOutOfBounds();

		void ProcessBulletCollision(ICollider* otherCollider);
		void ProcessEnemyCollision(ICollider* otherCollider);
		void ProcessPlayerCollision(ICollider* otherCollider);
		void ProcessBunkerCollision(ICollider* otherCollider);
	public:
		BulletController(BulletType type, Entity::EntityType ownerType);
		virtual ~BulletController() override;

		void Initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		void Update() override;
		void Render() override;

		sf::Vector2f GetProjectilePosition() override;
		BulletType GetBulletType();

		Entity::EntityType GetOwnerEntityType();

		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* otherCollider)override;

	};
}