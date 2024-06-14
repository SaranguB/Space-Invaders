#pragma once
#include <SFML/Graphics.hpp>

class PlayerService
{
private:

	int score = 0;
	sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
	float movementSpeed = 350.0f;

	const sf::String playerTexturePath = "assets/textures/player_ship.png";

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::RenderWindow* gameWindow;

	void InitializePlayerSprite();
	void ProcessPlayerInput();


public:

	PlayerService();
	~PlayerService();

	void Initialize();
	void Update();
	void Render();

	void MoveLeft();
	void MoveRight();
	int GetMoveSpeed();
	sf::Vector2f GetPosition();
};