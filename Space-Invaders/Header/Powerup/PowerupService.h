#pragma once
#include "../../Header/Collectible/Collectible.h"
#include <vector>
#include "SFML/System/Vector2.hpp"

namespace Powerup
{
	enum class PowerType;
	class PowerupController;

	class PowerupService 
	{
	private:
		std::vector <Collectible::ICollectible*> powerupList;
		PowerupController* CreatePowerUp(PowerType type);
		void Destroy();
	
	public:
		PowerupService();
		virtual ~PowerupService();

		void Initialize();
		void Update();
		void Render();
	
		PowerupController* SpawnPowerup(PowerType powerupType, sf::Vector2f position );
		void DestroyPowerup(PowerupController* powerupController);


	};
}


