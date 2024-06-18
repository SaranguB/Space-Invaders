#include "../../Header/UI/UIService.h"
#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"


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
	}

	void UI::UIService::Render()
	{
		mainMenuUIController->Render();
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
