#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Gameplay
{
	using namespace Global;
	using namespace UI::UIElement;

	GameplayView::GameplayView()
	{
		CreateUIElment();
	}
	void GameplayView::CreateUIElment()
	{
		gameplayImage = new ImageView();
	}

	GameplayView::~GameplayView()
	{
		Destroy();
	}

	void GameplayView::Destroy()
	{
		delete(gameplayImage);
	}

	void GameplayView::Initialize()
	{
		InitializeBackgroundSprite();
		
	}

	void GameplayView::InitializeBackgroundSprite()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		gameplayImage->Initialize(Config::background_texture_path,
			gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));
	}

	void GameplayView::Update()
	{
		gameplayImage->Update();
	}
	void GameplayView::Render()
	{
		gameplayImage->Render();
	}
}