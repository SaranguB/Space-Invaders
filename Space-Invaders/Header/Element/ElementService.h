#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../header/Element/Bunker/BunkerController.h"
#include "../../header/Element/Bunker/BunkerModel.h"


namespace Element
{
	class ElementService
	{

	private:
		const std::vector<Bunker::BunkerData> bunkerDataList = 
		{
			Bunker::BunkerData(sf::Vector2f(130.f,800.f)),
			Bunker::BunkerData(sf::Vector2f(430.0f,800.f)),
			Bunker::BunkerData(sf::Vector2f(730.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1130.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1430.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1730.0f, 800.f))
		};

		std::vector<Bunker::BunkerController*> bunkerList;

		void Destroy();

	public:
		ElementService();
		~ElementService();

		void Intialize();
		void Update();
		void Render();

		void Reset();



	};
}
