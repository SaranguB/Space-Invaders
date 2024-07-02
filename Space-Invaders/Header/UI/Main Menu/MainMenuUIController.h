#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ButtonView.h"



namespace UI
{

	namespace MainMenu
	{

		class MainMenuUIController : public Interface::IUIcontroller
		{
		private:

			const float buttonWidth = 400.f;
			const float buttonHeight = 140.f;

			const float playButtonYposition = 500.f;
			const float instructionButtonYPosition = 700.f;
			const float quitButtonYPosition = 900.f;

			const float backgroundAlpha = 85.f;

			UIElement::ImageView* backgroundImage;

			UIElement::ButtonView* playButton;
			UIElement::ButtonView* instructionButton;
			UIElement::ButtonView* quitButton;

			void CreateImage();
			void CreateButton();
			void InitializeBackgroundImage();
			void InitializeButton();
			void RegisterButtonCallback();

			void PlayeButtonCallback();
			void InstructionButtonCallback();
			void QuitButtonCallback();

			void Destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();


			void Initialize() ;
			void Update() override;
			void Render() override;
			void Show();




		};

	}
}
