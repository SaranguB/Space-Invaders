#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"
#include "../Header/EventService.h"
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
			move(-1.0f * GetMoveSpeed());
		}
		if (eventService->PressedRightKey())
		{
			move(1.0f * GetMoveSpeed());
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


void PlayerService::move(float offsetX)
{
	position.x += offsetX;
}

int PlayerService::GetMoveSpeed()
{
	return movementSpeed;
}

sf::Vector2f PlayerService::GetPosition()
{
	return position;
}
