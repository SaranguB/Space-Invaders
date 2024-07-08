#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;
	
	
	BulletView::BulletView()
	{
		CreateUIElement();
	}
	BulletView::~BulletView()
	{
		Destroy();
	}
	void BulletView::CreateUIElement()
	{
		bulletImage = new ImageView();
	}

	void BulletView::Destroy()
	{
		delete(bulletImage);
	}

	sf::String BulletView::GetBulletTexturePath()
	{
		switch (bulletController->GetBulletType())
		{
		case BulletType::LASER_BULLET:
			return BulletConfig::laser_bullet_texture_path;
		case BulletType::FROST_BULLET:
			return BulletConfig::frost_beam_texture_path;
			
		case BulletType::TORPEDO:
			return BulletConfig::torpedoe_texture_path;
		}
	}


	void BulletView::Initialize(BulletController* controller)
	{
		bulletController = controller;
		InitializeImage();

	}

	void BulletView::InitializeImage()
	{
		bulletImage->Initialize(GetBulletTexturePath(),bulletSpriteWidth,
			bulletSpriteHeight,bulletController->GetProjectilePosition());
	}


	void BulletView::Update()
	{
		bulletImage->SetPosition(bulletController->GetProjectilePosition());
		bulletImage->Update();
	}

	void BulletView::Render()
	{
		bulletImage->Render();
	}

	const sf::Sprite& BulletView::GetPlayerSprite()
	{
		///printf("f");
		return bulletImage->GetSprite();
	}



}