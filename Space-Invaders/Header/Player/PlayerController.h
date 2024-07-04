#pragma once
#include <SFML/Graphics.hpp>
#include "../Event/EventService.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Player
{
	enum class PlayerState;
	class PlayerView;
	class PlayerModel;
	
	
	class PlayerController
	{
	private:

		PlayerModel* playerModel;
		PlayerView* playerView;
		Event::EventService* eventService;

		

		void processPlayerInput();
		void MoveLeft();
		void MoveRight();
		void FireBullet();


	public:

		PlayerController(Entity::EntityType entityType);
		~PlayerController();

		void Initialize();
		void Update();
		void Render();


		sf::Vector2f GetPlayerPosition();
		Entity::EntityType GetEntityType();
	};
}


