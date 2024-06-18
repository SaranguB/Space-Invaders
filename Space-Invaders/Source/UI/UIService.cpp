#include "../../Header/UI/UIService.h"
#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"


namespace UI
{

	using namespace Main;
	using namespace MainMenu;
	UI::UIService::UIService()
	{
		mainMenuController = nullptr;
		CreateControllers();

	}


	void UI::UIService::CreateControllers()
	{
		mainMenuController = new MainMenuUIController();
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
	}


	void UI::UIService::InitializeController()
	{
		mainMenuController->Initialize();
	}

	void UI::UIService::Destroy()
	{
		delete(mainMenuController);
		mainMenuController = nullptr;

	}
}
