#pragma once
#include <SFML/Graphics.hpp>
#include "../Player/playerModel.h"
#include "../Player/PlayerView.h"

class PlayerController
{
private:

	PlayerModel* playerModel;
	PlayerView* playerView;
	ServiceLocator* serviceLocator;
	

	void processPlayerInput();
	void MoveLeft();
	void MoveRight();


public:

	PlayerController();
	~PlayerController();

	void Initialize();
	void Update();
	void Render();


	sf::Vector2f GetPlayerPosition();
};


