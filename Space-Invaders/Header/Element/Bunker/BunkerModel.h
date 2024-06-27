#pragma once
#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker 
	{


		struct BunkerData
		{
			sf::Vector2f position;

			BunkerData(sf::Vector2f position);
			BunkerData();
		};
	}
}