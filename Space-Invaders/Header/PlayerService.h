#pragma once
#include <SFML/Graphics.hpp>
#include "../Header/Player/PlayerController.h"

class PlayerService
{
private:

	PlayerController* playerController;

	sf::RenderWindow* gameWindow;



public:

	PlayerService();
	~PlayerService();

	void Initialize();
	void Update();
	void Render();

	
};