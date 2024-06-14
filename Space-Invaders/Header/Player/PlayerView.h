#pragma once
#include <SFML/Graphics.hpp>
#include "../Player/PlayerController.h"

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

	void Initialize();
	void Update();
	void Render();

	void Initialize(PlayerController* controller);

};