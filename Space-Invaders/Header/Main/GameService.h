#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	enum GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
	};


	class GameService
	{
	private:

		static GameState currentState;
		Global::ServiceLocator* serviceLocator;
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
		static void SetGameState(GameState newState);
		static GameState GetGameState();





	};
}
