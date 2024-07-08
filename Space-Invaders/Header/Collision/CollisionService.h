#pragma once
#include <vector>

namespace Collision
{
	class ICollider;
	class CollisionService
	{

	private:
		std::vector <ICollider*> colliderList;

		void ProcessCollision();
		void DoCollision(int indexI, int indexJ);
		bool HasCollisionOccured(int indexI, int indexJ);
		bool AreActiveCollidors(int intexI, int intexJ);



	public:
		CollisionService();
		~CollisionService();

		void Intialize();
		void Update();

		void AddCollider(ICollider* collider);
		void RemoveCollider(ICollider* collider);



	};
}