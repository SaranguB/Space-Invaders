#include "../../Header/Bullet/BulletController.h"
#include"../../Header/Bullet/BulletModel.h"
#include"../../Header/Bullet/BulletView.h"

namespace Bullet
{
	
	BulletController::BulletController(BulletType type)
	{
	}
	BulletController::~BulletController()
	{
	}
	void BulletController::Initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
	}
	void BulletController::Update()
	{
	}
	void BulletController::Render()
	{
	}
	sf::Vector2f BulletController::GetProjectilePosition()
	{
		return sf::Vector2f();
	}
	BulletType BulletController::GetBulletType()
	{
		return BulletType();
	}
	void BulletController::UpdateProjectilePosition()
	{
	}
	void BulletController::MoveUP()
	{
	}
	void BulletController::MoveDown()
	{
	}
	void BulletController::HandleOutOfBounds()
	{
	}
}