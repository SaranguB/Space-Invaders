#pragma once
#include <SFML/Graphics.hpp>

namespace Collision
{
	enum class CollisionState
	{
		ENABLED,
		DISABLED,
	};

	class ICollider
	{
	private:
		CollisionState collisionState;

	public:
		ICollider();
		~ICollider();

		virtual const sf::Sprite& GetCollidorSprite() = 0;
		virtual void OnCollision(ICollider* otherCollider) = 0;

		void EnableCollision();
		void DisableCollision();
		CollisionState GetCollisionState();

	};
}
