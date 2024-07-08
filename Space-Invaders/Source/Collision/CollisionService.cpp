#include "../../Header/Collision/CollisionService.h"
#include "../../Header/Collision/ICollider.h"
#include <iostream>

namespace Collision
{

	CollisionService::CollisionService()
	{
		//std::cout << colliderList.size();
	}
	CollisionService::~CollisionService()
	{
	}
	void CollisionService::Intialize()
	{
	}
	void CollisionService::Update()
	{
		ProcessCollision();	
	}


	void CollisionService::ProcessCollision()
	{
		for (int i = 0;i < colliderList.size();i++)
		{
			for (int j = i + 1; j < colliderList.size();j++)
			{
				DoCollision(i, j);
				//printf("i=%d, j=%d", i, j);
			}
		}
	}

	void CollisionService::DoCollision(int indexI, int indexJ)
	{
		if (colliderList[indexI]->GetCollisionState() == CollisionState::DISABLED ||
			colliderList[indexJ]->GetCollisionState() == CollisionState::DISABLED)return;

		if (HasCollisionOccured(indexI, indexJ))
		{
			
			if(AreActiveCollidors(indexI, indexJ))
			colliderList[indexI]->OnCollision(colliderList[indexJ]);

			if (AreActiveCollidors(indexI, indexJ))
			colliderList[indexJ]->OnCollision(colliderList[indexI]);
		}
	}

	bool CollisionService::HasCollisionOccured(int indexI, int indexJ)
	{

		//ICollider* collider1 = colliderList[indexI];
		//ICollider* collider2 = colliderList[indexJ];

		//if (collider1 == nullptr || collider2 == nullptr)
		//{
		//	// Log an error message if any collider is null
		//	printf("Null collider detected: indexI=%d, indexJ=%d\n", indexI, indexJ);
		//	return false;
		//}
		//else
		//{
		//	printf("not null");
		//}


		const sf::Sprite& colliderOneSprite = colliderList[indexI]->GetColliderSprite();
		
		
		const sf::Sprite& colliderTwoSprite = colliderList[indexJ]->GetColliderSprite();
		//printf("hooo");
		return colliderOneSprite.getGlobalBounds().intersects(colliderTwoSprite.getGlobalBounds());

	}

	bool CollisionService::AreActiveCollidors(int intexI, int intexJ)
	{
		return(intexI < colliderList.size() && intexJ < colliderList.size() &&
			colliderList[intexI] != nullptr && colliderList[intexJ] != nullptr);
	}

	void CollisionService::AddCollider(ICollider* collider)
	{

			colliderList.push_back(collider);
		
	}

	void CollisionService::RemoveCollider(ICollider* collider)
	{
		colliderList.erase(std::remove(colliderList.begin(), colliderList.end(), collider), colliderList.end());
	}

}