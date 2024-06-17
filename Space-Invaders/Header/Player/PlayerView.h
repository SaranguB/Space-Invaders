#pragma once
#include <SFML/Graphics.hpp>

class PlayerController;
class PlayerView
{
private:

	PlayerController* playerController;

	const sf::String playerTexturePath = "assets/textures/player_ship.png";
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	const float playerSpriteWidth = 60.f;
	const float playerSpriteHeight = 60.f;

	sf::RenderWindow* gameWindow;

	void InitializePlayerSprite();
	void ScalePlayerSprite();



public:
	PlayerView();
	~PlayerView();

	void Initialize(PlayerController* controller);
	void Update();
	void Render();


};