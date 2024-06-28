  #include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"


#include <iostream>




namespace Player
{
	using namespace Global;
	using namespace Event;
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


		EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

		if (eventService->PressedLeftKey() || eventService->PressedAKey())
		{

			MoveLeft();
		}
		if (eventService->PressedRightKey() || eventService->PressedDKey())
		{

			MoveRight();
		}
		if (eventService->PressedLeftMouseButton())
		{
			FireBullet();
		}

	}

	void PlayerController::MoveLeft()
	{
		using namespace Global;

		sf::Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x -= playerModel->PlayerMovementSpeed *
			ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		currentPosition.x = std::max(currentPosition.x, playerModel->LeftMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);

	}

	void PlayerController::MoveRight()
	{
		using namespace Global;

		sf::Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x += playerModel->PlayerMovementSpeed *
			ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPosition.x = std::min(currentPosition.x, playerModel->RightMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);
	}
	void PlayerController::FireBullet()
	{
		ServiceLocator::GetInstance()->GetBulletServices()->SpawnBullet(Bullet::BulletType::TORPEDO,
			playerModel->GetPlayerPosition() + playerModel->barrelPositionOffset,
			Bullet::MovementDirection::UP);
	}
}


