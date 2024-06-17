#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{

	enum class PlayerState;
	class PlayerView;
	class PlayerModel;

	class PlayerController
	{
	private:

		PlayerModel* playerModel;
		PlayerView* playerView;



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
}


