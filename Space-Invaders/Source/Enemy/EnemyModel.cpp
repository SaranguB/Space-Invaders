#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include<iostream>

namespace Enemy
{

	EnemyModel::EnemyModel(EnemyType type, Entity::EntityType entityType )
	{
		enemyType = type;
	}

	EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::Initialize()
	{
		enemyState = EnemyState::PATROLLING;
		movementDirection = MovementDirection::RIGHT;
		enemyPosition = referencePosition;
	}

	sf::Vector2f EnemyModel::GetEnemyPosition()
	{
		return enemyPosition;
	}

	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}

	sf::Vector2f EnemyModel::GetReferencePosition()
	{
		return referencePosition;
	}

	void EnemyModel::SetReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}

	void EnemyModel::SetMovementDirection(MovementDirection direction)
	{

		movementDirection = direction;
	}

	MovementDirection EnemyModel::GetMovementDirection()
	{
		return movementDirection;
	}
	EnemyState EnemyModel::GetEnemyState()
	{
		return enemyState;
	}

	void EnemyModel::SetEnemyState(EnemyState state)
	{
		enemyState = state;
	}

	EnemyType EnemyModel::GetEnemyType()
	{
		return enemyType;
	}

	void EnemyModel::SetEnemyType(EnemyType type)
	{
		enemyType = type;
	}

}


