#pragma once
#include <SFML/Graphics.hpp>
#include "../Event/EventService.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Player/PlayerModel.h"


namespace Player
{
	enum class PlayerState;
	class PlayerView;
		

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

		void ProcessBulletFire();
		void FireBullet(bool bTrippleLaser = false);
		void FireBullet(sf::Vector2f position);

		void UpdateFireDuration();
		void UpdatePowerupDuration();

		void DisableShield();
		void DisableRapidFire();
		void DisableTrippleLaser();

		

	public:

		PlayerController();
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

		void DecreasePlayerLives();
		inline void IncreasesEnemiesKilled(int val) { PlayerModel::enemiesKilled += val; }

		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* otherCollider) override;
	};
}


