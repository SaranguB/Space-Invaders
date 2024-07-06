#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"


namespace Bullet
{
	enum class BulletType;
	enum class MovementDirection;

	class BulletModel
	{
	private:

		float movementSpeed = 300.f;
		sf::Vector2f bulletPosition;

		BulletType bulletType;
		MovementDirection movementDirection;
		Entity::EntityType ownerType;

	public:
		BulletModel(BulletType type, Entity::EntityType ownerType);
		~BulletModel();

		void Initialize(sf::Vector2f position, MovementDirection direction);
		
		void SetBulletType(BulletType type);
		BulletType GetBulletType();

		void SetMovementDirection(MovementDirection movementDirection);
		MovementDirection GetMovementDirection();

		sf::Vector2f GetbulletPosition();
		void SetBulletPosition(sf::Vector2f position);

		float GetMovementSpeed();
		void SetMovementSpeed(float speed);
		
		Entity::EntityType GetOwnerEntityType();
	};
}
