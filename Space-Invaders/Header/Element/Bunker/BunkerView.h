#pragma once
#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker
	{
		class BunkerController;
		class BunkerView
		{

		private:
			const float bunkerWidth = 80.f;
			const float bunkerHeight = 80.f;

			BunkerController* bunkerController;
			sf::RenderWindow* gameWindow;

			sf::String BunkerPath = "assets/textures/bunker.png";

			sf::Texture bunkerTexture;
			sf::Sprite bunkerSprite;

			void InitializeImage();
			void ScaleSprite();

		public:

			BunkerView();
			~BunkerView();

			void Initialize(BunkerController* controller);
			void Update();
			void Render();
		};

	}
}
