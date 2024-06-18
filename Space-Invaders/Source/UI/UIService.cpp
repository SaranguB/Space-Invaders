#include "../../Header/UI/UIService.h"
#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include <iostream>


namespace UI
{

	using namespace Main;
	using namespace MainMenu;
	UI::UIService::UIService()
	{
		mainMenuUIController = nullptr;
		CreateControllers();

	}


	void UI::UIService::CreateControllers()
	{
		mainMenuUIController = new MainMenuUIController();
	}

	UI::UIService::~UIService()
	{
		Destroy();
	}

	void UI::UIService::Initialize()
	{
		InitializeController();
	}

	void UI::UIService::Update()
	{
		//std::cout << "hi";
		switch (GameService::GetGameState())
		{
			
		case GameState::MAIN_MENU:
			return mainMenuUIController->Update();
			break;
		}
	}

	void UI::UIService::Render()
	{
		switch (GameService::GetGameState())
		{
			
		case GameState::MAIN_MENU:
			return mainMenuUIController->Render();
			std::cout << "hi";
			break;
		}
		
	}


	void UI::UIService::InitializeController()
	{
		mainMenuUIController->Initialize();
	}

	void UI::UIService::Destroy()
	{
		delete(mainMenuUIController);
		mainMenuUIController = nullptr;

	}
}
