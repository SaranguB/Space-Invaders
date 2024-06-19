#include "../../Header/Event/EventService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include <iostream>

namespace Event
{

	using namespace Global;

	EventService::EventService()
	{
		gameWindow = nullptr;
	}

	EventService::~EventService() = default;


	void EventService::Initialize()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	}

	void EventService::Update()
	{
		UpdateMouseButtonState(leftMouseButtonState, sf::Mouse::Left);
		UpdateMouseButtonState(rightMouseButtonState, sf::Mouse::Right);
		updateKeyboardButtonsState(leftArrowButtonState, sf::Keyboard::Left);
		updateKeyboardButtonsState(rightArrowButtonState, sf::Keyboard::Right);
		updateKeyboardButtonsState(AButtonState, sf::Keyboard::A);
		updateKeyboardButtonsState(DButtonState, sf::Keyboard::D);

	}

	void EventService::UpdateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton)
	{
		if (sf::Mouse::isButtonPressed(mouseButton))
		{
			switch (currentButtonState)
			{
			case ButtonState::RELEASED:
				currentButtonState = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				currentButtonState = ButtonState::HELD;
				break;
			}
		}
		else
		{
			currentButtonState = ButtonState::RELEASED;
		}
	}

	void EventService::updateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton)
	{
		if (sf::Keyboard::isKeyPressed(keyboardButton))
		{
			switch (currentButtonState)
			{
			case ButtonState::RELEASED:
				currentButtonState = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				currentButtonState = ButtonState::HELD;
				break;
			}
		}
		else
		{
			currentButtonState = ButtonState::RELEASED;
		}

	}

	void EventService::ProcessEvents()
	{

		if (IsGameWindowOpen())
		{
			while (gameWindow->pollEvent(gameEvent))
			{
				if (GameWindowWasClosed() || HasQuitGame())
				{
					gameWindow->close();
				}
			}
		}

	}

	bool EventService::HasQuitGame()
	{

		return (IsKeayboardEvent() && PressedEscapeKey());
	}

	bool EventService::IsKeayboardEvent()
	{
		return gameEvent.type == sf::Event::KeyPressed;
	}

	bool EventService::PressedLeftKey()
	{
		return leftArrowButtonState == ButtonState::HELD;

	}
	bool EventService::PressedRightKey()
	{
		return  rightArrowButtonState== ButtonState::HELD;

	}

	

	bool EventService::PressedAKey()
	{
		return AButtonState == ButtonState::HELD;;
	}

	bool EventService::PressedDKey()
	{
		return DButtonState == ButtonState::HELD;;

	}
	bool EventService::PressedLeftMouseButton()
	{
		/*if (gameEvent.key.code == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Left)
		{
			std::cout << "pressed";
		}*/
		return leftMouseButtonState == ButtonState::PRESSED;
	}

	bool EventService::PressedRightMouseButton()
	{

		return rightMouseButtonState == ButtonState::PRESSED;


	}

	bool EventService::PressedEscapeKey()
	{
		return gameEvent.key.code == sf::Keyboard::Escape;
	}


	bool EventService::IsGameWindowOpen()
	{
		return gameWindow != nullptr;
	}

	bool EventService::GameWindowWasClosed()
	{

		return gameEvent.type == sf::Event::Closed;
	}
}


