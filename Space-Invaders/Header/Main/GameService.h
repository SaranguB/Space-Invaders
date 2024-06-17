#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"


class GameService
{
private:

	ServiceLocator* serviceLocator;
	sf::RenderWindow* gameWindow;

	void initialize();
	void destroy();
public:
	GameService();
    ~GameService();

	void ignite();
	void update();
	void render();
	bool isRunning();

	void InitializeVariable();





};
