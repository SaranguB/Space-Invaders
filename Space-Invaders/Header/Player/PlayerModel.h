#pragma once
#include <SFML/Graphics.hpp>

enum class PlayerState
{
	ALIVE,
	DEAD,
};

class PlayerModel
{

private:

	const sf::Vector2f initialPlayerPosition = sf::Vector2f(500.f,500.0f);
	sf::Vector2f playerPosition;
	int PlayerScore;
	PlayerState playerState;

public:

	const float PlayerMovementSpeed = 200.0f;
	PlayerModel();
	~PlayerModel();;

	void Initialize();

	sf::Vector2f LeftMostPosition = sf::Vector2f(50.f,0.f);
	sf::Vector2f RightMostPosition = sf::Vector2f(700.f,0.f);

	void Reset();
	sf::Vector2f GetPlayerPosition();
	void SetPlayerPosition(sf::Vector2f position);

	PlayerState GetPlayerState();
	void SetPlayerState(PlayerState state);

};