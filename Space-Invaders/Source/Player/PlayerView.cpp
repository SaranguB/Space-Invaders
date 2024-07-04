#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include <iostream>


namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView()
	{
		CreateUIElement();
		gameWindow = nullptr;
	}


	void PlayerView::CreateUIElement()
	{
		playerImage = new ImageView();
	}

	sf::String PlayerView::GetPlayerTexturePath()
	{
		return Config::player_texture_path;
	}

	void PlayerView::Destroy()
	{
		delete(playerImage);
	}


	PlayerView::~PlayerView()
	{
		Destroy();
	}

	void PlayerView::Initialize(PlayerController* controller)
	{
		playerController = controller;
		InitializePlayerSprite();
	}

	void PlayerView::InitializePlayerSprite()
	{

		playerImage->Initialize(GetPlayerTexturePath(),
			playerSpriteWidth, playerSpriteHeight, playerController->GetPlayerPosition());
	}



	void PlayerView::Update()
	{
		playerImage->SetPosition(playerController->GetPlayerPosition());
		playerImage->Update();
		
	}

	void PlayerView::Render()
	{
		playerImage->Render();
	}
}

