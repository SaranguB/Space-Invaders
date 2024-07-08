#pragma once
#include<SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerModel.h"
#include "../../Header/Collision/ICollider.h"


namespace Element
{
	namespace Bunker
	{
		class BunkerView;

		class BunkerController :public Collision::ICollider
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

			const sf::Sprite& GetColliderSprite() override;
			void OnCollision(ICollider* otherCollider) override;
		};
	}
}
