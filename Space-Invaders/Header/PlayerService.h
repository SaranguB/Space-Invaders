#pragma once
#include <SFML/Graphics.hpp>

class PlayerService
{
private:

	int health = 3;
	int score = 0;
	sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
	int movementSpeed = 2;

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

	void move(float offsetX);
	int GetMoveSpeed();
	sf::Vector2f GetPosition();
};