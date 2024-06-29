#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;
	PowerupService::PowerupService()
	{
	}
	PowerupService::~PowerupService()
	{
	}
	void PowerupService::Destroy()
	{
	}
	void PowerupService::Initialize()
	{
	}

	void PowerupService::Update()
	{
	}

	void PowerupService::Render()
	{
	}

	
	PowerupController* PowerupService::CreatePowerUp(PowerType type)
	{
		return nullptr;
	}
	PowerupController* PowerupService::SpawnPowerup(PowerType powerupType, sf::Vector2f position)
	{
		return nullptr;
	}

	void PowerupService::DestroyPowerup(PowerupController* powerupController)
	{
	}

	
}