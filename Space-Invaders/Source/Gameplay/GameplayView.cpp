#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	GameplayView::GameplayView()
	{
	}
	GameplayView::~GameplayView()
	{
	}
	void GameplayView::Initialize()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeBackgroundSprite();
		

	}

	void GameplayView::InitializeBackgroundSprite()
	{
		if (backgroundTexture.loadFromFile(backgroundTexturePath))
		{
			backgroundSprite.setTexture(backgroundTexture);
			scaleBackgroundSprite();
		}
	}


	void GameplayView::scaleBackgroundSprite()
	{
		backgroundSprite.setScale(
			static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
			static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
		);
	}

	

	void GameplayView::Update()
	{
	}
	void GameplayView::Render()
	{
		gameWindow->draw(backgroundSprite);
	}
}