#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"
#include "../Header/EventService.h"
#include "../Header/TimeService.h"
#include <iostream>

PlayerService::PlayerService()
{
	playerController = new PlayerController();
}

PlayerService::~PlayerService()
{
	delete(playerController);
	playerController = nullptr;
}

void PlayerService::Initialize()
{

	playerController->Initialize();
	
}

void PlayerService::Update()
{

	playerController->Update();


}

void PlayerService::Render()
{
	playerController->Render();

}