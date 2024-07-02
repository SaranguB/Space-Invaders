#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/Config.h"

namespace Enemy
{
	using namespace Graphic;
	using namespace Global;
	using namespace UI::UIElement;

	Enemy::EnemyView::EnemyView()
	{
		CreateUIElement();
	}

	Enemy::EnemyView::~EnemyView()
	{

	}

	void Enemy::EnemyView::Initialize(EnemyController* controller)
	{
		enemyController = controller;
		InitializeEnemySprite();
	}


	void EnemyView::InitializeEnemySprite()
	{
		enemyImage->Initialize(GetEnemyTexturePath(),
			enemySpriteWidth, enemySpriteHeight, enemyController->GetEnemyPosition());
	}

	void EnemyView::Destroy()
	{
		delete(enemyImage);
	}

	void EnemyView::CreateUIElement()
	{
		enemyImage = new ImageView();
	}

	sf::String EnemyView::GetEnemyTexturePath()
	{

		switch (enemyController->GetEnemyType())
		{

		case Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;


		case Enemy::EnemyType::SUBZERO:

			return Config::subzero_texture_path;


		case Enemy::EnemyType::THUNDER_SNAKE:

			return Config::thunder_snake_texture_path;


		case Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;

		}
	}


	void Enemy::EnemyView::update()
	{
		enemyImage->SetPosition(enemyController->GetEnemyPosition());
		enemyImage->Update();
	}

	void Enemy::EnemyView::Render()
	{
		enemyImage->Render();
	}
}
