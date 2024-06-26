#pragma once

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
		DIAGONAL_LEFT,
		DIAGONAL_RIGHT,
	};

	enum class EnemyType
	{
		ZAPPER ,
		SUBZERO,
		//UFO,   ..2
		THUNDER_SNAKE,  
	};
	enum class EnemyState
	{
		ATTACK,
		DEAD,
		PATROLLING,
	};
}