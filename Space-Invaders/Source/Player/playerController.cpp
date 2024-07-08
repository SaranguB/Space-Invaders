#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Event/EventService.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Entity/EntityConfig.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../Header/Sound/SoundService.h"


#include <iostream>




namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Time;
	using namespace Bullet;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;

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
		switch (playerModel->GetPlayerState())
		{
		case PlayerState::ALIVE:
			processPlayerInput();
			break;
		case PlayerState::FROZEN:
			UpdateFreezDuration();
		}

		UpdateFireDuration();
		UpdatePowerupDuration();
		playerView->Update();

	}



	void PlayerController::Render()
	{
		playerView->Render();
	}

	void PlayerController::Reset()
	{
		playerModel->Reset();
	}

	sf::Vector2f PlayerController::GetPlayerPosition()
	{
		return playerModel->GetPlayerPosition();
	}

	PlayerState PlayerController::GetPlayerState()
	{
		return playerModel->GetPlayerState();
	}


	const sf::Sprite& PlayerController::GetColliderSprite()
	{
		//printf("l");
		return playerView->GetPlayerSprite();
	}

	void PlayerController::OnCollision(ICollider* otherCollider)
	{
		if (ProcessPowerupCollision(otherCollider))
		{
			return;
		}
		if (ProcessBulletCollision(otherCollider))
		{
			return;
		}
		ProcessEnemyCollision(otherCollider);
	}

	bool PlayerController::ProcessBulletCollision(ICollider* otherCollider)
	{
		if (playerModel->IsShieldEnabled())
			return false;

		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

		if (bulletController && bulletController->GetOwnerEntityType() != EntityType::PLAYER)
		{
			if (bulletController->GetBulletType() == BulletType::FROST_BULLET)
			{
				playerModel->SetPlayerState(PlayerState::FROZEN);
				playerModel->elapsedFreezDuration = playerModel->freezeDuration;

			}
			if (bulletController->GetBulletType() == BulletType::LASER_BULLET ||
				bulletController->GetBulletType() == BulletType::TORPEDO)
			{
				DecreasePlayerLives();
			}


			return true;
		}
		return false;
	}


	bool PlayerController::ProcessEnemyCollision(ICollider* otherCollider)
	{
		if (playerModel->IsShieldEnabled())
			return false;
		EnemyController* enemyController = dynamic_cast<EnemyController*> (otherCollider);
		if (enemyController)
		{
			DecreasePlayerLives();;
			return true;
		}
		return false;
	}



	bool PlayerController::ProcessPowerupCollision(ICollider* otherCollider)
	{
		PowerupController* powerupController = dynamic_cast<PowerupController*> (otherCollider);

		if (powerupController)
		{
			return true;
		}
		return false;
	}

	void PlayerController::UpdatePowerupDuration()
	{

		if (playerModel->elapsedShieldDuration > 0)
		{
			elapsedShieldDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			if (playerModel->elapsedShieldDuration < 0)
				DisableShield();
		}

		if (playerModel->elapsedRapidFireDuration > 0)
		{
			elapsedRapidFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			if (playerModel->elapsedRapidFireDuration < 0)
				DisableRapidFire();

		}
		if (playerModel->elapsedTrippleLaserDuration > 0)
		{
			playerModel->elapsedTrippleLaserDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			if (playerModel->elapsedTrippleLaserDuration < 0)
				DisableTrippleLaser();
		}

	}

	void PlayerController::EnableShield()
	{
		playerModel->elapsedShieldDuration = playerModel->shieldPowerupDuration;
		playerModel->SetShieldState(true);
	}

	void PlayerController::DisableShield()
	{
		playerModel->SetShieldState(false);
	}

	void PlayerController::EnableRapidFire()
	{
		playerModel->elapsedRapidFireDuration = playerModel->rapidFirePowerupDuration;
		playerModel->SetRapidFireState(true);
	}

	void PlayerController::DisableRapidFire()
	{
		playerModel->SetRapidFireState(false);

	}

	void PlayerController::EnableTripleLaser()
	{
		playerModel->elapsedTrippleLaserDuration = playerModel->trippleLaserPowerupDuration;
		playerModel->SetTrippleFireState(true);
	}

	void PlayerController::DisableTrippleLaser()
	{
		playerModel->SetTrippleFireState(false);
	}

	void PlayerController::DecreasePlayerLives()
	{
		PlayerModel::playerLives -= 1;
		
		if (playerModel->playerLives <= 0)
		{
			Reset();
		}
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

	void PlayerController::UpdateFireDuration()
	{
		if (playerModel->elapsedFireDuration > 0)
		{
			elapsedFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		}
	}

	void PlayerController::UpdateFreezDuration()
	{
		if (playerModel->elapsedFreezDuration > 0)
		{
			playerModel->elapsedFreezDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedFreezDuration <= 0)
			{
				playerModel->SetPlayerState(PlayerState::ALIVE);
			}
		}
	}

	void PlayerController::ProcessBulletFire()
	{
		if (playerModel->elapsedFireDuration > 0)return;

		if (playerModel->IsTrippleLaserEnabled())
			FireBullet(true);

		else FireBullet();

		if (playerModel->IsRapidFireEnabled())
			playerModel->elapsedFireDuration = playerModel->rapidFireCooldownDration;

		else playerModel->elapsedFireDuration = playerModel->fireCooldownDuration;	
	}

	void PlayerController::FireBullet(bool bTrippleLaser)
	{
		sf::Vector2f bulletPosition = playerModel->GetPlayerPosition() + playerModel->barrelPositionOffset;
		
		FireBullet(bulletPosition);

		if (bTrippleLaser)
		{
		 bulletPosition = playerModel->GetPlayerPosition() + playerModel->secondWeponPositionOffset;
		 bulletPosition = playerModel->GetPlayerPosition() + playerModel->thirdWeponPositionOffset;

		}
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::BUTTON_CLICK);
	}

	void PlayerController::FireBullet(sf::Vector2f position)
	{
		ServiceLocator::GetInstance()->GetBulletServices()->SpawnBullet(BulletType::LASER_BULLET, position,
			Bullet::MovementDirection::UP, playerModel->GetEntityType());
	}

}


