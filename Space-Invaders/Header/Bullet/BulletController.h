#pragma once
#include "../../Header/Projectile/IProjectile.h"

namespace Bullet
{
	enum class BulletType;
	class BulletView;
	class BulletModel;

	class BulletController : public Projectile::IProjectile
	{
	protected:

		BulletView* bulletView;
		BulletModel* bulletModel;

		void UpdateProjectilePosition() override;

		void MoveUP();
		void MoveDown();

		void HandleOutOfBounds();

	public:
		BulletController(BulletType type);
		virtual ~BulletController() override;

		void Initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		void Update() override;
		void Render() override;

		sf::Vector2f GetProjectilePosition() override;
		BulletType GetBulletType();

	};
}