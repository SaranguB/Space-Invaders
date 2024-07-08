#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"
#include <iostream>


namespace UI
{

	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
	using namespace UIElement;
	using namespace GameplayUI;
	using namespace SplashScreen;

	UI::UIService::UIService()
	{
		mainMenuUIController = nullptr;
		gameplayUIController = nullptr;
		splashScreenUIController = nullptr;
		CreateControllers();

	}


	void UI::UIService::CreateControllers()
	{
		mainMenuUIController = new MainMenuUIController();
		gameplayUIController = new GameplayUIController();
		splashScreenUIController = new SplashScreenUIController();
	}

	UI::UIService::~UIService()
	{
		Destroy();
	}

	void UI::UIService::Initialize()
	{
		TextView::InitializeTextView();

		InitializeController();
	}

	void UI::UIService::Update()
	{
		IUIcontroller* uiController = GetCurrentUIController();
		//std::cout << "hi";
		if (uiController)uiController->Update();

	}

	void UI::UIService::Render()
	{
		IUIcontroller* uiController = GetCurrentUIController();
		if (uiController)uiController->Render();

	}

	void UIService::ShowScreen()
	{
		//printf("illa");
		IUIcontroller* uiController = GetCurrentUIController();
		if (uiController)uiController->Show();

	}


	void UI::UIService::InitializeController()
	{
		mainMenuUIController->Initialize();
		gameplayUIController->Initialize();
		splashScreenUIController->Initialize();

	}

	void UI::UIService::Destroy()
	{
		delete(mainMenuUIController);
		delete(gameplayUIController);
		delete(splashScreenUIController);


	}

	IUIcontroller* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splashScreenUIController;

		case GameState::MAIN_MENU:
			return mainMenuUIController;

		case GameState::GAMEPLAY:
			return gameplayUIController;
		default:
			return nullptr;
		}
	}


}
