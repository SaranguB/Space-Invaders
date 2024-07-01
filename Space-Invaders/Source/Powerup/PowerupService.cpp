#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerup/Controllers/OutscalBombController.h"
#include "../../Header/Powerup/Controllers/RapidFireController.h"
#include "../../Header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Powerup/Controllers/TrippleLaserController.h"




namespace Powerup
{
	using namespace Global;
	using namespace Controller;
	using namespace Collectible;
	PowerupService::PowerupService()
	{
	}
	PowerupService::~PowerupService()
	{
		Destroy();
	}
	void PowerupService::Destroy()
	{
		for (int i = 0;i < powerupList.size();i++)
		{
			delete(powerupList[i]);
		}
	}
	void PowerupService::Initialize()
	{
	}

	void PowerupService::Update()
	{
		for (int i = 0;i < powerupList.size();i++)
		{
			powerupList[i]->Update();
		}
	}

	void PowerupService::Render()
	{
		for (int i = 0;i < powerupList.size();i++)
		{
			powerupList[i]->Render();
		}
	}

	
	PowerupController* PowerupService::CreatePowerup(PowerupType powerupType)
	{
		switch (powerupType)
		{
		case PowerupType::TRIPPLE_LASER:
			return new TrippleLaserController(Powerup::PowerupType::TRIPPLE_LASER);

		case PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);

		case PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);
		}
	}
	PowerupController* PowerupService::SpawnPowerup(PowerupType powerupType, sf::Vector2f position)
	{
		PowerupController* powerupController = CreatePowerup(powerupType);
		powerupController->Initialize(position);
		powerupList.push_back(powerupController);
		return powerupController;
	}

	void PowerupService::DestroyPowerup(PowerupController* powerupController)
	{
		powerupList.erase(std::remove(powerupList.begin(), powerupList.end(), powerupController), powerupList.end());
		delete(powerupController);
	}

	
}	