#pragma once
#include <SFML/Graphics.hpp>


namespace Player
{
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
}