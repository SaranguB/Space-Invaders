#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class Player
{
private:

	int playerHealth = 3;
	int playerScore = 0;
	sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);


public:

	int moveSpeed = 5;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	int GetScore()
	{
		return playerScore;
	}
	void SetScore(int newScore)
	{
		playerScore += newScore;
	}
	sf::Vector2f GetPosition()
	{
		return position;
	}
	void SetPosition()
	{

	}

	void move();
	void TakeDamage();
	void Move();
	void ShootBullets();

};

int main()
{
	sf::VideoMode videoMod(800, 600);
	sf::RenderWindow window(videoMod, "space invader");

	Player player;
	player.playerTexture.loadFromFile("assets/textures/player_ship.png");
	player.playerSprite.setTexture(player.playerTexture);
	player.playerSprite.setScale(.5, .5);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move();
		}

		window.clear(sf::Color::Blue);

		player.playerSprite.setPosition(player.GetPosition());
		
		window.draw(player.playerSprite);

		

		window.display();
	}


	return 0;
}