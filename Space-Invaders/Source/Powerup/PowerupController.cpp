#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupView.h"
#include "../../header/Powerup/PowerupModel.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;
	PowerupController::PowerupController(PowerupType type)
	{
		powerupView = new PowerupView();
		powerupModel = new PowerupModel(type);

	}

	PowerupController::~PowerupController()
	{
		delete(powerupModel);
		delete(powerupView);

	}
	void PowerupController::Initialize(sf::Vector2f position)
	{
		powerupView->Initialize(this);
		powerupModel->Intialize(position);


	}

	void PowerupController::Update()
	{
		powerupView->Update();
		HandleOutOfBonds();
		UpdatePowerPosition();

	}
	void PowerupController::UpdatePowerPosition()
	{
		sf::Vector2f currentPosition = powerupModel->GetPowerupPosition();
		currentPosition.y += powerupModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		powerupModel->SetPowerupPosition(currentPosition);
	}

	void PowerupController::HandleOutOfBonds()
	{
		sf::Vector2f powerupPosition = GetCollectiblePosition();
		sf::Vector2f windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x
			|| powerupPosition.y<0 || powerupPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetPowerupServices()->DestroyPowerup(this);
		}
	}

	void PowerupController::Render()
	{
		powerupView->Render();
	}

	void PowerupController::OnCollected()
	{
	}

	PowerupType PowerupController::GetpowerupType()
	{
		return powerupModel->GetPowerupType();
	}

	sf::Vector2f PowerupController::GetCollectiblePosition()
	{
		return powerupModel->GetPowerupPosition();
	}
}