#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD,
	};

	class PlayerModel
	{

	private:

		const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.0f, 950.0f);
		sf::Vector2f playerPosition;
		int PlayerScore;
		PlayerState playerState;


	public:

		const float PlayerMovementSpeed = 200.0f;
		PlayerModel();
		~PlayerModel();;

		void Initialize();

		const sf::Vector2f LeftMostPosition = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f RightMostPosition = sf::Vector2f(1800.f, 950.f);
		sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 50.f);


		void Reset();
		sf::Vector2f GetPlayerPosition();
		void SetPlayerPosition(sf::Vector2f position);

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);

	};
}