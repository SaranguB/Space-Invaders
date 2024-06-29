#include "../../Header/Powerup/PowerUpModel.h"

namespace Powerup
{
	PowerupModel::PowerupModel(PowerupType type)
	{
		powerupType = type;
	}

	PowerupModel::~PowerupModel()
	{
	}

	void PowerupModel::Intialize(sf::Vector2f Position)
	{
		powerupPosition = Position;
	}

	void PowerupModel::SetPowerupPosition(sf::Vector2f position)
	{
		powerupPosition = position;
	}

	sf::Vector2f PowerupModel::GetPowerupPosition()
	{
		return powerupPosition;
	}
	void PowerupModel::SetPowerupType(PowerupType type)
	{
		powerupType = type;
	}
	PowerupType PowerupModel::GetPowerupType()
	{
		return powerupType;
	}
	float PowerupModel::GetMovementSpeed()
	{
		return movementSpeed;
	}
	void PowerupModel::SetMovementSpeed(float speed)
	{
		movementSpeed = speed;
	}
}