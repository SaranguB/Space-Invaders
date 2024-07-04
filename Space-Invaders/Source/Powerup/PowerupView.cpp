#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	PowerupView::PowerupView()
	{

		CreateUIElement();
	}

	PowerupView::~PowerupView()
	{
		Destroy();
	}
	void PowerupView::Initialize(PowerupController* controller)
	{
		powerupController = controller;
		InitializeImage();
	}

	void PowerupView::CreateUIElement()
	{
		powerupImage = new ImageView();
	}

	void PowerupView::InitializeImage()
	{
		powerupImage->Initialize(GetPowerupTexturePath(), spriteWidth, spriteHeight,
			powerupController->GetCollectiblePosition());

	}
	sf::String PowerupView::GetPowerupTexturePath()
	{
		switch (powerupController->GetPowerupType())
		{
		case PowerupType::TRIPPLE_LASER:
			return Config::laser_bullet_texture_path;

		case PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;

		case PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case PowerupType::SHIELD:
			return Config::shield_texture_path;

		}
	}
	void PowerupView::Destroy()
	{
		delete(powerupImage);
	}

	void PowerupView::Update()
	{
		powerupImage->SetPosition(powerupController->GetCollectiblePosition());
		powerupImage->Update();
	}
	void PowerupView::Render()
	{
		powerupImage->Render();
	}
}