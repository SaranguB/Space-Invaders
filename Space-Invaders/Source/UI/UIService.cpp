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
		printf("illa");
		IUIcontroller* uiController = GetCurrentUIController();
		if (uiController)uiController->Show();

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

	IUIcontroller* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuUIController;

		default:
			return nullptr;
		}
	}

	
}
