#include "../header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	CreateServices();
}

ServiceLocator::~ServiceLocator()
{
	ClearAllServices();
}

void ServiceLocator::CreateServices()
{
	graphicService = new GraphicService();
}

void ServiceLocator::ClearAllServices()
{
	delete(graphicService);
	graphicService = nullptr;
}

ServiceLocator* ServiceLocator::GetInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::Initialize()
{
	graphicService->Initialize();
	//to initilize 
}

void ServiceLocator::Update()
{
	graphicService->Update();

	//to update
}

void ServiceLocator::Render()
{
	graphicService->Render();

	// to render
}

GraphicService* ServiceLocator::GetGraphicService()
{
	return graphicService;
}

