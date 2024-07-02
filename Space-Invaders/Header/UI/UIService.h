#pragma once
#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIcontroller.h"


namespace UI
{

	class UIService : public IUIcontroller
	{
	private:

		MainMenu::MainMenuUIController* mainMenuUIController;

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