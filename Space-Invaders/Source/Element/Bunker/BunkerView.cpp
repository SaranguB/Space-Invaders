#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;
		BunkerView::BunkerView()
		{
		}
		BunkerView::~BunkerView()
		{
		}
		void BunkerView::Intialize(BunkerController* controller)
		{
			bunkerController = controller;
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeImage();
		}
		void BunkerView::InitializeImage()
		{
			if (bunkerTexture.loadFromFile(BunkerPath))
			{
				bunkerSprite.setTexture(bunkerTexture);
			}
		}

		void BunkerView::ScaleSprite()
		{
			bunkerSprite.setScale(
				static_cast<float>(bunkerWidth) / bunkerSprite.getTexture()->getSize().x,
				static_cast<float>(bunkerHeight) / bunkerSprite.getTexture()->getSize().y
			);
		}

		void BunkerView::Update()
		{
			bunkerSprite.setPosition(bunkerController->GetBunkerPosition());
		}
		void BunkerView::Render()
		{
			gameWindow->draw(bunkerSprite);
		}
	}
}