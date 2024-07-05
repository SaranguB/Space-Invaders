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


		bool ProcessBulletCollision(ICollider* otherCollider);
		bool ProcessPowerupCollision(ICollider* otherCollider);
		bool ProcessEnemyCollision(ICollider* otherCollider);
		void UpdateFreezDuration();

		void UpdateFireDuration();
		void ProcessBulletFire();
		void FireBullet(bool bTrippleLaser = false);
		void FireBullet(sf::Vector2f position);

		void UpdateFireDuration();
		void UpdatePowerupDuration();

		void DisableShield();
		void DisableRapidFire();
		void DisableTrippleLaser();

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
		void OnCollision(ICollider* otherCollider) override;
	};
}


