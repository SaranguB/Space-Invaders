#include "../../Header/Element/ElementService.h"

namespace Element
{
	using namespace Bunker;

	

	ElementService::ElementService()
	{
	}
	ElementService::~ElementService()
	{
	}
	void ElementService::Intialize()
	{
		for (int i = 0;i < bunkerDataList.size();i++)
		{
			BunkerController* bunkerController = new BunkerController();

			bunkerController->Initialize(bunkerDataList[i]);

			bunkerList.push_back(bunkerController);
		}

	}
	void ElementService::Update()
	{
		for (int i = 0; i < bunkerDataList.size();i++)
		{
			bunkerList[i]->Update();
		}
	}
	void ElementService::Render()
	{
		for (int i = 0;i < bunkerDataList.size();i++)
		{
			bunkerList[i]->Render();
		}
	}
	void ElementService::Destroy()
	{
		for (int i = 0;i < bunkerDataList.size();i++)
		{
			delete(bunkerList[i]);
		}

	}
	void ElementService::Reset()
	{
		Destroy();
	}
}

