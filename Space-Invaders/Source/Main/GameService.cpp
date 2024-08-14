#include "../../Header/Main/GameService.h";

namespace Main
{
	using namespace Global;

	GameState GameService::currentState = GameState::BOOT;
	GameService::GameService()
	{
		serviceLocator = nullptr;
	}

	GameService::~GameService()
	{
		destroy();
		//destructor
	}

	void GameService::ignite()
	{
		using namespace Global;
		serviceLocator = ServiceLocator::GetInstance();
		initialize();
		//starts the game
	}



	void GameService::initialize()
	{
		serviceLocator->Initialize();
		InitializeVariable();
		ShowSplashScreen();

		//to initialize
	}
	void GameService::InitializeVariable()
	{
		gameWindow = serviceLocator->GetGraphicService()->GetGameWindow();
	}
	void GameService::ShowMainMenu()
	{
		SetGameState(GameState::MAIN_MENU);
	}
	void GameService::destroy()
	{
		//clean up resources
	}

	void GameService::ShowSplashScreen()
	{
		SetGameState(GameState::SPLASH_SCREEN);
		ServiceLocator::GetInstance()->GetUIService()->ShowScreen();
	}

	void GameService::update()
	{
		serviceLocator->GetEventService()->ProcessEvents();
		serviceLocator->Update();

		// Updates the game logic and game state.
	}

	void GameService::render()
	{
		gameWindow->clear();
		serviceLocator->Render();
		gameWindow->display();

	}

	bool GameService::isRunning()
	{
		return serviceLocator->GetGraphicService()->IsGameWindowOpen();
		// Checks if the game is currently running.
	}
	void GameService::SetGameState(GameState newState)
	{
		currentState = newState;
	}
	GameState GameService::GetGameState()
	{
		return currentState;
	}
}