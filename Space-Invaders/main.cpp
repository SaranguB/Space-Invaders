#include <SFML/Graphics.hpp>
int main()
{

	sf::VideoMode video(1280, 270);
	sf::RenderWindow window(video, "SFML window");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)

				window.close();
		}

		window.clear(sf::Color::Blue);
		window.display();


	}

	return 0;
}