#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	BulletModel::BulletModel(BulletType type)
	{
		bulletType = type;
	}

	BulletModel::~BulletModel()
	{
	}

	void BulletModel::Initialize(sf::Vector2f position, MovementDirection direction)
	{
		bulletPosition = position;
		movementDirection = direction;
	}

	void BulletModel::Update()
	{
	}

	void BulletModel::Render()
	{
	}

	void BulletModel::SetBulletType(BulletType type)
	{
		bulletType = type;
	}

	BulletType BulletModel::GetBulletType()
	{
		return bulletType;
	}

	void BulletModel::SetMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}

	MovementDirection BulletModel::GetMovementDirection()
	{
		return movementDirection;
	}

	sf::Vector2f BulletModel::GetbulletPosition()
	{
		return bulletPosition;
	}

	void BulletModel::SetBulletPosition(sf::Vector2f position)
	{
		bulletPosition = position;
	}

	float BulletModel::GetMovementSpeed()
	{
		return movementSpeed;
	}

	void BulletModel::SetMovementSpeed(float speed)
	{
		movementSpeed = speed;
	}
}