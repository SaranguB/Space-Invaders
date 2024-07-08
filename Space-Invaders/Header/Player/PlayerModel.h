#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD,
		FROZEN,
	};

	class PlayerModel
	{

	private:

		friend class PlayerController;

		friend void UI::GameplayUI::GameplayUIController::UpdateEnemiesKilledText();
		friend void UI::GameplayUI::GameplayUIController::DrawplayerLives();


		const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.0f, 950.0f);
		sf::Vector2f playerPosition;
		int PlayerScore;
		PlayerState playerState;
		Entity::EntityType entityType;

		bool bShield;
		bool bRapidFire;
		bool bTrippleLaser;
		
		const int maxPlayerLives = 3;
		static int playerLives;
		static int enemiesKilled;

	public:

		const float PlayerMovementSpeed = 200.0f;
		PlayerModel();
		~PlayerModel();;

		void Initialize();

		const sf::Vector2f LeftMostPosition = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f RightMostPosition = sf::Vector2f(1800.f, 950.f);
		sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 50.f);
		sf::Vector2f secondWeponPositionOffset = sf::Vector2f(45.f, 0.f);
		sf::Vector2f thirdWeponPositionOffset = sf::Vector2f(-45.f, 0.f);

		const float	shieldPowerupDuration = 10.f;
		const float rapidFirePowerupDuration = 10.f;
		const float trippleLaserPowerupDuration = 10.f;

		const float freezeDuration = 2.f;

		const float	fireCooldownDuration = .2f;
		const float rapidFireCooldownDration = 0.05f;
		const float trippleLaserCooldownDuration = 30.f;

		float elapsedShieldDuration;
		float elapsedRapidFireDuration;
		float elapsedTrippleLaserDuration;

		float elapsedFireDuration;
		float elapsedFreezDuration;

		void Reset();
		sf::Vector2f GetPlayerPosition();
		void SetPlayerPosition(sf::Vector2f position);

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);

		Entity::EntityType GetEntityType();

		bool IsShieldEnabled();
		bool IsRapidFireEnabled();
		bool IsTrippleLaserEnabled();

		void SetShieldState(bool value);
		void SetRapidFireState(bool value);
		void SetTrippleFireState(bool value);

	};
}