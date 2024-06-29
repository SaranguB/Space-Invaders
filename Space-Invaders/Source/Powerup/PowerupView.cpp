#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace Powerup
{
	using namespace Global;
	PowerupView::PowerupView()
	{

	}

	PowerupView::~PowerupView()
	{
	}
	void PowerupView::Initialize(PowerupController* controller)
	{
		powerupController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage(powerupController->GetPowerupType());
	}

	void PowerupView::InitializeImage(PowerupType type)
	{
		switch (type)
		{
		case PowerupType::TRIPPLE_LASER:
			if (powerupTexture.loadFromFile(Config::tripple_laser_texture_path))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
		case PowerupType::OUTSCAL_BOMB:
			if (powerupTexture.loadFromFile(Config::outscal_bomb_texture_path))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();

			}
		case PowerupType::RAPID_FIRE:
			if (powerupTexture.loadFromFile(Config::rapid_fire_texture_path))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();

			}
		case PowerupType::SHIELD:
			if (powerupTexture.loadFromFile(Config::shield_texture_path))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();

			}

		}
	}
	void PowerupView::ScaleImage()
	{
		powerupSprite.setScale(
			static_cast<float>(spriteWidth) / powerupSprite.getTexture()->getSize().x,
			static_cast<float>(spriteHeight) / powerupSprite.getTexture()->getSize().y
		);
	}
	void PowerupView::Update()
	{
		powerupSprite.setPosition(powerupController->GetCollectiblePosition());
	}
	void PowerupView::Render()
	{
		gameWindow->draw(powerupSprite);
	}
}