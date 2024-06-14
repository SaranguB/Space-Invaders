#include "../header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	eventService = nullptr;
	playerService = nullptr;
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

}

void ServiceLocator::ClearAllServices()
{
	delete(graphicService);
	graphicService = nullptr;
	delete(eventService);
    eventService = nullptr;

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

	//to initilize 
}

void ServiceLocator::Update()
{
	graphicService->Update();
	eventService->Update();
	playerService->Update();


	//to update
}

void ServiceLocator::Render()
{
	graphicService->Render();
	playerService->Render();

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


