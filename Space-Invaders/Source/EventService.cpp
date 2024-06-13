#include "../Header/EventService.h"
#include "../Header/GameService.h"
#include "../Header/GraphicService.h"


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
	return gameEvent.key.code == sf::Keyboard::Left;

}
bool EventService::PressedRightKey()
{
	return gameEvent.key.code == sf::Keyboard::Right;

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

