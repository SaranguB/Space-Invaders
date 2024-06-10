#include <SFML/Graphics.hpp>
int main()
{

	sf::VideoMode video(800, 600);
	sf::RenderWindow window(video, "SFML window");
	window.setFramerateLimit(60);

	int spaceY = 200;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)

				window.close();
		}

		window.clear(sf::Color::Blue);

		sf::CircleShape circle(50);
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(50, spaceY);

		sf::CircleShape square(50, 4);
		square.setFillColor(sf::Color::Red);
		square.setPosition(300, spaceY);

		sf::CircleShape triangle(50, 3);
		triangle.setFillColor(sf::Color::Blue);
		triangle.setPosition(550, spaceY);

		sf::Texture file;
		file.loadFromFile("assets/textures/outscal_logo.png");
		sf::Sprite outscal;
		outscal.setTexture(file);
		outscal.setRotation(45);
		outscal.setPosition(200, spaceY);
		outscal.setScale(.5, .5);
		window.draw(outscal);


		sf::Font font;
		font.loadFromFile("assets/fonts/OpenSans.ttf");
		sf::Text sfml("sfml is awsome",font,50);
		window.draw(sfml);

		

		window.display();


	}

	return 0;
}