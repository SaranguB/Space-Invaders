#pragma once

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
	};

	enum class EnemyType
	{
		ZAPPER ,
		SUBZERO,
		//UFO,   ..2
		//THUNDER_SNAKE,   ..3
	};
	enum class EnemyState
	{
		ATTACK,
		DEAD,
		PATROLLING,
	};
}