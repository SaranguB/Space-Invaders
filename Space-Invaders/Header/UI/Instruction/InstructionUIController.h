#pragma once
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	namespace InstructionUI
	{
		class InstructionUIController : public Interface::IUIcontroller
		{
		private:
			UIElement::ImageView* instructionImage;
			UIElement::ButtonView* menuButton;
			UIElement::ImageView* backgroundImage;
			sf::RenderWindow* gameWindow;

			const float buttonWidth = 200.f;
			const float buttonHeight = 100.f;

			const float menuButtonXposition = 850.f;
			const float menuButtonYposition = 970.f;

			const float fontSize = 30.f;

			const sf::Color textColor = sf::Color::White;

		public:
			InstructionUIController();
			~InstructionUIController();

			float waveXposition;
			float waveYPosition;

			void Initialize() override;
			void Update() override;
			void Render() override;


			void InitialzeInstructionImage();
			void InitializeButton();
			void MenuButtonCallback();

			sf::Vector2f GetImagecentreAligned();
			void RegisterButtonCallback();

			void Show();

		};
	}
}
