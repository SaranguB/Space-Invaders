#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"


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


			UI::UIElement::ImageView* bunkerImage;
			void InitializeImage();
			void CreateUIElement();
	
			void Destroy();

		public:

			BunkerView();
			~BunkerView();

			void Initialize(BunkerController* controller);
			void Update();
			void Render();
		};

	}
}
