#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Entity/EntityConfig.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Sound/SoundService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;
	using namespace Collision;
	using namespace Entity;
	using namespace Player;
	using namespace Sound;


	Enemy::EnemyController::EnemyController(EnemyType type)
	{
		//printf("hi");

		enemyView = new EnemyView();
		enemyModel = new EnemyModel(type);

	}

	Enemy::EnemyController::~EnemyController()
	{
		delete(enemyView);
		delete(enemyModel);

	}

	void Enemy::EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyModel->SetEnemyPosition(getRandomInitialPosition());
		enemyView->Initialize(this);

	}

	void Enemy::EnemyController::Update()
	{
		enemyView->update();
		Move();
		handleOutOfBounds();
		UpdateFireTime();
		ProcessBulletFire();

	}

	void EnemyController::UpdateFireTime()
	{
		elapsedFireDuration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyController::ProcessBulletFire()
	{
		if (elapsedFireDuration > rateOfFire)
		{
			FireBullet();
			elapsedFireDuration = 0.f;
		}
	}



	sf::Vector2f EnemyController::getRandomInitialPosition()
	{

		float xOffsetDistance = (std::rand() % static_cast<int>(enemyModel->RightMostPosition.x -
			enemyModel->LeftMostPosition.x));

		float xPosition = enemyModel->LeftMostPosition.x + xOffsetDistance;

		float yPosition = enemyModel->LeftMostPosition.y;

		return sf::Vector2f(xPosition, yPosition);


	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = GetEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (enemyPosition.x< 0 || enemyPosition.x >windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y>windowSize.y)
		{
			ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
		}
	}

	void Enemy::EnemyController::Render()
	{
		enemyView->Render();
	}
	void EnemyController::Move()
	{
		/*switch (enemyModel->GetMovementDirection())
		{

		case MovementDirection::LEFT:
			MoveLeft();
			break;

		case MovementDirection::RIGHT:
			MoveRight();
			break;

		case MovementDirection::DOWN:
			MoveDown();
			break;

		}*/
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}

	EnemyType EnemyController::GetEnemyType()
	{
		return enemyModel->GetEnemyType();
	}

	EnemyState EnemyController::GetEnemyState()
	{
		return enemyModel->GetEnemyState();
	}

	const sf::Sprite& EnemyController::GetColliderSprite()
	{
		return enemyView->GetEnemySprite();
	}

	void EnemyController::OnCollision(ICollider* otherCollider)
	{
		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

		if (bulletController && bulletController->GetOwnerEntityType() != EntityType::ENEMY)
		{
			Destroy();
			return;
		}
		PlayerController* playerController = dynamic_cast<PlayerController*>(otherCollider);

		if (playerController)
		{
			Destroy();
			return;
		}
	}

	void EnemyController::Destroy()
	{
		ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
	}


}
