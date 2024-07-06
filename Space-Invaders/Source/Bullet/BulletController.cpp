#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../header/Element/Bunker/BunkerController.h"

namespace Bullet
{
	using namespace Global;
	using namespace Entity;
	using namespace Player;
	using namespace Enemy;
	using namespace Element::Bunker;

	BulletController::BulletController(BulletType type, Entity::EntityType ownerType)
	{
		bulletView = new BulletView();
		bulletModel = new BulletModel(type, ownerType);
	}
	BulletController::~BulletController()
	{
		delete(bulletView);
		delete(bulletModel);

	}
	void BulletController::Initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bulletView->Initialize(this);
		bulletModel->Initialize(position, direction);
	}
	void BulletController::Update()
	{
		UpdateProjectilePosition();
		bulletView->Update();
		HandleOutOfBounds();
	}

	void BulletController::UpdateProjectilePosition()
	{
		switch (bulletModel->GetMovementDirection())
		{
		case Bullet::MovementDirection::DOWN:
			MoveDown();
			break;

		case Bullet::MovementDirection::UP:
			MoveUP();
			break;

		}
	}



	void BulletController::MoveUP()
	{
		sf::Vector2f currentPosition = bulletModel->GetbulletPosition();
		currentPosition.y -= bulletModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		bulletModel->SetBulletPosition(currentPosition);
	}

	void BulletController::MoveDown()
	{
		sf::Vector2f currentPosition = bulletModel->GetbulletPosition();
		currentPosition.y += bulletModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		bulletModel->SetBulletPosition(currentPosition);
	}

	void BulletController::HandleOutOfBounds()
	{
		sf::Vector2f bulletPosition = GetProjectilePosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetBulletServices()->DestroyBullet(this);
		}
	}

	const sf::Sprite& BulletController::GetColliderSprite()
	{
		//printf("j");
		return bulletView->GetPlayerSprite();
	}

	void BulletController::OnCollision(ICollider* otherCollider)
	{
		ProcessBulletCollision(otherCollider);
		ProcessBunkerCollision(otherCollider);
		ProcessEnemyCollision(otherCollider);
		ProcessPlayerCollision(otherCollider);
	}

	void BulletController::ProcessBulletCollision(ICollider* otherCollider)
	{
		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

		if (bulletController)
		{
			ServiceLocator::GetInstance()->GetBulletServices()->DestroyBullet(this);
		}
	}

	void BulletController::ProcessEnemyCollision(ICollider* otherCollider)
	{
		EnemyController* enemyController = dynamic_cast<EnemyController*>(otherCollider);

		if (enemyController && GetOwnerEntityType() != EntityType::ENEMY)
		{
			ServiceLocator::GetInstance()->GetBulletServices()->DestroyBullet(this);
		}
	}

	void BulletController::ProcessPlayerCollision(ICollider* otherCollider)
	{
		PlayerController* playerController = dynamic_cast<PlayerController*>(otherCollider);

		if (playerController && GetOwnerEntityType() != EntityType::ENEMY)
			ServiceLocator::GetInstance()->GetBulletServices()->DestroyBullet(this);

	}

	void BulletController::ProcessBunkerCollision(ICollider* otherCollider)
	{
		BunkerController* bunkerController = dynamic_cast<BunkerController*>(otherCollider);
		if (bunkerController)
			ServiceLocator::GetInstance()->GetBulletServices()->DestroyBullet(this);

	}

	void BulletController::Render()
	{
		bulletView->Render();
	}
	sf::Vector2f BulletController::GetProjectilePosition()
	{
		return bulletModel->GetbulletPosition();
	}
	BulletType BulletController::GetBulletType()
	{
		return bulletModel->GetBulletType();
	}

	Entity::EntityType BulletController::GetOwnerEntityType()
	{
		return bulletModel->GetOwnerEntityType();
	}





}