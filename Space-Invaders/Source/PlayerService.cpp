#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"
#include "../Header/EventService.h"
#include "../Header/TimeService.h"
#include <iostream>

PlayerService::PlayerService()
{
	gameWindow = nullptr;
}

PlayerService::~PlayerService()
{
}

void PlayerService::Initialize()
{

	gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	InitializePlayerSprite();
}

void PlayerService::Update()
{

	ProcessPlayerInput();
	playerSprite.setPosition(GetPosition());

}

void PlayerService::Render()
{
	gameWindow->draw(playerSprite);
}

void PlayerService::ProcessPlayerInput()
{
	EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

	if (eventService->IsKeayboardEvent())
	{
		if (eventService->PressedLeftKey())
		{
			MoveLeft();
		}
		if (eventService->PressedRightKey())
		{
			MoveRight();
		}
	}
}

void PlayerService::InitializePlayerSprite()
{
	
	if (playerTexture.loadFromFile(playerTexturePath))
	{

		playerSprite.setTexture(playerTexture);
	}
}


void PlayerService::MoveLeft()
{
	position.x -= movementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
}

void PlayerService::MoveRight()
{
	position.x += movementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
}

int PlayerService::GetMoveSpeed()
{
	return movementSpeed;
}

sf::Vector2f PlayerService::GetPosition()
{
	return position;
}
