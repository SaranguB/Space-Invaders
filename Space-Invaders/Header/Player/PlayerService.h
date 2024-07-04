#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"


namespace Player
{
	class PlayerController;

	class PlayerService
	{
	private:

		PlayerController* playerController;

		sf::RenderWindow* gameWindow;



	public:

		PlayerService(Entity::EntityType entityType);
		~PlayerService();

		void Initialize();
		void Update();
		void Render();

		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();

		void Reset();

	};
}