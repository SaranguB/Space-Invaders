#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"

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
		InitializeEnemySprite();
	}


	void EnemyView::InitializeEnemySprite()
	{
		if (enemyTexture.loadFromFile(enemyTexturePath))
		{
			enemySprite.setTexture(enemyTexture);
			ScaleEnemySprite();
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
