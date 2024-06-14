#include "../header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	eventService = nullptr;
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
	//to initilize 
}

void ServiceLocator::Update()
{
	graphicService->Update();
	eventService->Update();

	//to update
}

void ServiceLocator::Render()
{
	graphicService->Render();
	eventService->Update();
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


