#pragma once
#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIcontroller.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"



namespace UI
{

	class UIService 
	{
	private:

		MainMenu::MainMenuUIController* mainMenuUIController;
		GameplayUI::GameplayUIController* gameplayUIController;
		SplashScreen::SplashScreenUIController* splashScreenUIController;

		void CreateControllers();
		void InitializeController();
		void Destroy();
		Interface::IUIcontroller* GetCurrentUIController();

	public:

		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();
		void ShowScreen();


	};
}