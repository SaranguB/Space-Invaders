#include "../../Header/Global/ServiceLocator.h"

namespace Global
{
	using namespace Graphic;
	using namespace Event;
	using namespace Player;
	using namespace Time;
	using namespace UI;

	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		timeService = nullptr;
		uiService = nullptr;
		CreateServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		ClearAllServices();
	}

	void ServiceLocator::CreateServices()
	{
		graphicService = new GraphicService();
		eventService = new EventService();
		playerService = new PlayerService();
		timeService = new TimeService();
		uiService = new UIService();

	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		graphicService = nullptr;
		delete(eventService);
		eventService = nullptr;
		delete(playerService);
		playerService = nullptr;
		delete(timeService);
		timeService = nullptr;
		delete(uiService);
		uiService = nullptr;



	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::Initialize()
	{
		graphicService->Initialize();
		eventService->Initialize();
		playerService->Initialize();
		timeService->Initialize();
		uiService->Initialize();


		//to initilize 
	}

	void ServiceLocator::Update()
	{
		graphicService->Update();
		eventService->Update();
		playerService->Update();
		timeService->Update();
		uiService->Update();

		//to update
	}

	void ServiceLocator::Render()
	{
		graphicService->Render();
		playerService->Render();
		uiService->Render();

		// to render
	}

	GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicService;
	}

	EventService* ServiceLocator::GetEventService()
	{
		return eventService;
	}

	PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}

	TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}

	UI::UIService* ServiceLocator::GetUIService()
	{
		return uiService;
	}

}
