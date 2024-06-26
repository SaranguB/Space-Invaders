#pragma once
#include<SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerModel.h"

namespace Element
{
	class BunkerView;
	namespace Bunker
	{
		class BunkerController
		{
		private:

			BunkerView* bunkerView;
			BunkerData bunkerData;

		public:

			BunkerController();
			 ~BunkerController();


			void Initialize(BunkerData data);
			void Update();
			void Render();

			sf::Vector2f GetBunkerPosition();
		};
	}
}
