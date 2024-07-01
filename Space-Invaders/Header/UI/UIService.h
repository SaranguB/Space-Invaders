#pragma once
#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIcontroller.h"
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UI
	{
		enum class UIState
		{
			VISIBLE,
			HIDDEN,
		};

		class UIView
		{
		protected:

			MainMenu::MainMenuUIController* mainMenuUIController;

			sf::RenderWindow* gameWindow;
			UIState uiState;

		
			
			Interface::IUIcontroller* GetCurrentUIController();

		public:

			UIService();
			virtual ~UIService();

			void Initialize();
			void Update();
			void Render();
			void ShowScreen();


		};
	}
}