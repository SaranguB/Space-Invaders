#include "../../Header/Player/PlayerService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Player/PlayerController.h"
#include <iostream>

namespace Player
{
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
}