#include "../../Header/Element/ElementService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Collision/ICollider.h"

namespace Element
{
	using namespace Bunker;
	using namespace Global;
	using namespace Collision;


	ElementService::ElementService()
	{
	}
	ElementService::~ElementService()
	{
		Destroy();
	}
	void ElementService::Intialize()
	{
		SpawnBunkers();

	}
	void ElementService::Update()
	{
		for (int i = 0; i < bunkerList.size();i++)
		{
			bunkerList[i]->Update();
		}
		DestroyFlaggedBunkers();	
	}
	void ElementService::Render()
	{
		for (int i = 0;i < bunkerList.size();i++)
		{
			bunkerList[i]->Render();
		}
	}

	void ElementService::SpawnBunkers()
	{
		for (int i = 0;i < bunkerDataList.size();i++)
		{
			BunkerController* bunkerController = new BunkerController();

			bunkerController->Initialize(bunkerDataList[i]);
			bunkerList.push_back(bunkerController);

			ServiceLocator::GetInstance()->GetCollisionService()
				->AddCollider(dynamic_cast<ICollider*>(bunkerController));
		}
	}

	void ElementService::DestroyBunker(Bunker::BunkerController* bunkerController)
	{
		flaggedBunkerList.push_back(bunkerController);
		bunkerList.erase(std::remove(bunkerList.begin(),
			bunkerList.end(), bunkerController), bunkerList.end());
	}

	void ElementService::DestroyFlaggedBunkers()
	{
		for (int i = 0;i < flaggedBunkerList.size();i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()->
				RemoveCollider(dynamic_cast<ICollider*>(flaggedBunkerList[i]));
			delete(flaggedBunkerList[i]);
		}
		flaggedBunkerList.clear();
	}

	void ElementService::Destroy()
	{
		for (int i = 0;i < bunkerList.size();i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()
				->RemoveCollider(dynamic_cast<ICollider*>(bunkerList[i]));
			delete(bunkerList[i]);
		}
		bunkerList.clear();
	}

	void ElementService::Reset()
	{
		Destroy();
		SpawnBunkers();
	}

}

