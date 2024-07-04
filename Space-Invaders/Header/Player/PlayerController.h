#pragma once
#include <SFML/Graphics.hpp>
#include "../Event/EventService.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Player
{
	enum class PlayerState;
	class PlayerView;
	class PlayerModel;
	
	
	class PlayerController : public Collision::ICollider

	{
	private:

		PlayerModel* playerModel;
		PlayerView* playerView;
		Event::EventService* eventService;

		float elapsedShieldDuration;
		float elapsedRapidFireDuration;
		float elapsedTripleLaserDuration;

		float elapsedFireDuration;
		float elapsedFreezDuration;

		void processPlayerInput();
		void MoveLeft();
		void MoveRight();


		void ProcessBulletCollision();
		void ProcessPowerupCollision();
		void ProcessEnemyCollision();
		void UpdateFreezDuration();

		void UpdateFireDuration();
		void ProcessBulletFire();
		void FireBullet(bool b_tripple_laser = false);
		void FireBullet(sf::Vector2f position);

		void UpdateFireupDuration();

		void DisableShield();
		void DisableRapidFire();
		void DisableTrippleFire();

	public:

		PlayerController(Entity::EntityType entityType);
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		sf::Vector2f GetPlayerPosition();
		PlayerState GetPlayerState();

		void EnableShield();
		void EnableRapidFire();
		void EnableTripleLaser();


		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* collider) override;
	};
}


