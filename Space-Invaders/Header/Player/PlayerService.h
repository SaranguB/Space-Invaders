#pragma once
#include <SFML/Graphics.hpp>

class PlayerController;

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