#include "../../Header/Collision/CollisionService.h"
#include "../../Header/Collision/ICollider.h"

namespace Collision
{

	CollisionService::CollisionService()
	{
	}
	CollisionService::~CollisionService()
	{
	}
	void CollisionService::Intialize()
	{
	}
	void CollisionService::Update()
	{
	}
	void CollisionService::AddCollider(ICollider* collider)
	{
	}

	void CollisionService::ProcessCollision()
	{
		for (int i = 0;i < colliderList.size();i++)
		{
			for (int j = i + 1; j < colliderList.size();j++)
			{
				DoCollision(i, j);
			}
		}
	}

	void CollisionService::DoCollision(int indexI, int indexJ)
	{
		if (colliderList[indexI]->GetCollisionState() == CollisionState::DISABLED ||
			colliderList[indexJ]->GetCollisionState() == CollisionState::DISABLED)return;

		if (AreActiveCollidors(indexI, indexJ))
		{
			colliderList[indexI]->OnCollision(colliderList[indexJ]);

			colliderList[indexJ]->OnCollision(colliderList[indexI]);
		}
	}

	bool CollisionService::HasCollisionOccured(int indexI, int indexJ)
	{
		const sf::Sprite& colliderOneSprite = colliderList[indexI]->GetCollidorSprite();
		const sf::Sprite& colliderTwoSprite = colliderList[indexJ]->GetCollidorSprite();

	}
	bool CollisionService::AreActiveCollidors(int intexI, int intexJ)
	{
	}
}