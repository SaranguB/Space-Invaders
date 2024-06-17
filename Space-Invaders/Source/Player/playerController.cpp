#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>





PlayerController::PlayerController()
{
	playerView = new PlayerView();
	playerModel = new PlayerModel();
}

PlayerController::~PlayerController()
{
	delete(playerView);
	playerView = nullptr;
	delete(playerModel);
	playerModel = nullptr;
}

void PlayerController::Initialize()
{
	playerModel->Initialize();
	playerView->Initialize(this);

}

void PlayerController::Update()
{
	processPlayerInput();
	playerView->Update();

}



void PlayerController::Render()
{
	playerView->Render();
}

sf::Vector2f PlayerController::GetPlayerPosition()
{
	return playerModel->GetPlayerPosition();
}

void PlayerController::processPlayerInput()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		MoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		MoveRight();
	}

}

void PlayerController::MoveLeft()
{

	sf::Vector2f currentPosition = playerModel->GetPlayerPosition();
	currentPosition.x -= playerModel->PlayerMovementSpeed *
		ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	currentPosition.x = std::max(currentPosition.x, playerModel->LeftMostPosition.x);
	playerModel->SetPlayerPosition(currentPosition);
	
}

void PlayerController::MoveRight()
{

	sf::Vector2f currentPosition = playerModel->GetPlayerPosition();
	currentPosition.x += playerModel->PlayerMovementSpeed *
		ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

	currentPosition.x = std::min(currentPosition.x, playerModel->RightMostPosition.x);
	playerModel->SetPlayerPosition(currentPosition);
}


