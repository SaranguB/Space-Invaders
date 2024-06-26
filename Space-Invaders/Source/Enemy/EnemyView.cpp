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

	Enemy::EnemyView::EnemyView()
	{
	}

	Enemy::EnemyView::~EnemyView()
	{
	}

	void Enemy::EnemyView::Initialize(EnemyController* controller)
	{
		enemyController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeEnemySprite(enemyController->GetEnemyType());
	}


	void EnemyView::InitializeEnemySprite(EnemyType type)
	{
		switch (type)
		{
		case Enemy::EnemyType::ZAPPER:

			if (enemyTexture.loadFromFile(Config::zapper_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
				break;

			}

		case Enemy::EnemyType::SUBZERO:
		{
			if (enemyTexture.loadFromFile(Config::subzero_texture_path))
			{
				
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
				break;

			}
		}
		case Enemy::EnemyType::THUNDER_SNAKE:
			if (enemyTexture.loadFromFile(Config::thunder_snake_texture_path))
			{
				
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
				break;
			}
		}
	}

	void EnemyView::ScaleEnemySprite()
	{
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeight) / enemySprite.getTexture()->getSize().y
		);
	}
	void Enemy::EnemyView::update()
	{
		enemySprite.setPosition(enemyController->GetEnemyPosition());
	}

	void Enemy::EnemyView::Render()
	{
		gameWindow->draw(enemySprite);
	}
}
