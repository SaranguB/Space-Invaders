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


	void TakeDamage();
	void Move();
	void ShootBullets();

};

int main()
{
	sf::VideoMode videoMod(800, 600);
	sf::RenderWindow window(videoMod, "space invader");

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

		Player player;

		window.clear(sf::Color::Blue);

		window.display();
	}


	return 0;
}