#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>


namespace Player
{
	PlayerView::PlayerView()
	{
		gameWindow = nullptr;
	}

	PlayerView::~PlayerView()
	{

	}

	void PlayerView::Initialize(PlayerController* controller)
	{
		using namespace Global;
		playerController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializePlayerSprite();
	}

	void PlayerView::InitializePlayerSprite()
	{

		if (playerTexture.loadFromFile(playerTexturePath))
		{

			playerSprite.setTexture(playerTexture);
			ScalePlayerSprite();

		}
	}

	void PlayerView::ScalePlayerSprite()
	{

		playerSprite.setScale(

			static_cast<float>(playerSpriteWidth) / playerSprite.getTexture()->getSize().x,
			static_cast<float>(playerSpriteHeight) / playerSprite.getTexture()->getSize().y
		);
	}




	void PlayerView::Update()
	{
		playerSprite.setPosition(playerController->GetPlayerPosition());
	}

	void PlayerView::Render()
	{
		gameWindow->draw(playerSprite);
	}
}

