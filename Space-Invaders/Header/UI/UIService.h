#pragma once
#include "../../Header/UI/Main Menu/MainMenuUIController.h"


namespace UI
{

	class UIService
	{
	private:

		MainMenu::MainMenuUIController* mainMenuController;

		void CreateControllers();
		void InitializeController();
		void Destroy();


	public:

		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();


	};
}