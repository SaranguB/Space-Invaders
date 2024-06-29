#pragma once
#include <SFML/System/Vector2.hpp>
namespace Powerup
{
	enum class PowerupType;
	class PowerupModel
	{
	private:

		float movementSpeed = 300.f;
		sf::Vector2f powerupPosition;
		PowerupType powerupType;


	public:
		PowerupModel(PowerupType type);
		~PowerupModel();

		void Intialize(sf::Vector2f position);
		
		void SetPowerupPosition(sf::Vector2f position);
		sf::Vector2f GetPowerupPosition();

		void SetPowerupType(PowerupType type);
		PowerupType GetPowerupType();

		float GetMovementSpeed();
		void SetMovementSpeed(float speed);
	};
}
