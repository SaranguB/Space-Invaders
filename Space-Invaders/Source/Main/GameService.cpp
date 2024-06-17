#include "../../Header/Main/GameService.h";

GameService::GameService()
{
	serviceLocator = nullptr;
	gameWindow = nullptr;
}

GameService::~GameService()
{
	destroy();
	//destructor
}

void GameService::ignite()
{
	serviceLocator = ServiceLocator::GetInstance();
	initialize();
	//starts the game
}

void GameService::initialize()
{
	serviceLocator->Initialize();
	InitializeVariable();
	//to initialize
}
void GameService::InitializeVariable()
{
	gameWindow = serviceLocator->GetGraphicService()->GetGameWindow();
}
void GameService::destroy()
{
	//clean up resources
}

void GameService::update()
{
	serviceLocator->GetEventService()->ProcessEvents();
	serviceLocator->Update();
	
	// Updates the game logic and game state.
}

void GameService::render()
{
	gameWindow->clear(serviceLocator->GetGraphicService()->GetWindowColor());
	serviceLocator->Render();
	gameWindow->display();

}

bool GameService::isRunning()
{
	return serviceLocator->GetGraphicService()->IsGameWindowOpen();
	// Checks if the game is currently running.
}