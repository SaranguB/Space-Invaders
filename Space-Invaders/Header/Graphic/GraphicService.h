#pragma once

#include <SFML/Graphics.hpp>
using namespace std;

namespace Graphic
{


	class GraphicService
	{
	private:

		const string gameWindowTitle = "Space Invaded";
		const int gameWindowWidth = 800;
		const int gameWindowHeight = 600;
		const sf::Color windowColor = sf::Color::Blue;
		const int frameRate = 60;

		sf::VideoMode* videoMode;
		sf::RenderWindow* gameWindow;

		void SetVideoMethod();
		void OnDestroy();

	public:

		GraphicService();
		~GraphicService();

		void Initialize();
		void Update();
		void Render();

		sf::RenderWindow* CreateGameWindow();

		bool IsGameWindowOpen();

		sf::RenderWindow* GetGameWindow();
		sf::Color GetWindowColor();



	};
}