#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Event/EventService.h"
#include "../../header/Sound/SoundService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Event;
		using namespace Global;

		ButtonView::ButtonView() = default;

		ButtonView::~ButtonView() = default;

		void ButtonView::Initialize(sf::String title,
			sf::String texturePath, float buttonWidth, float buttonHeight, sf::Vector2f position)
		{
			ImageView::Initialize(texturePath, buttonWidth, buttonHeight, position);
			buttonTitle = title;

		}

		void ButtonView::RegisterCallBackFuntion(CallbackFunction buttonCallBack)
		{
			callbackFunction = buttonCallBack;
		}


		void ButtonView::Update()
		{
			ImageView::Update();
			if (uiState == UIState::VISIBLE)
			{
				HandleButtonInteraction();
			}
		}
	
		void ButtonView::Render()
		{
			ImageView::Render();

		}

		void ButtonView::HandleButtonInteraction()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

			if (ClickedButton(&imageSprite, mousePosition))
			{
				if (callbackFunction)
				{
					callbackFunction();
				}
			}
		}

		bool ButtonView::ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
		{
			return ServiceLocator::GetInstance()->GetEventService()->PressedLeftMouseButton() && 
				buttonSprite->getGlobalBounds().contains(mousePosition);
		}

		void ButtonView::PrintButtonClicked()
		{
			printf("Clicked %s", buttonTitle.toAnsiString().c_str());
		}
		
	}
}