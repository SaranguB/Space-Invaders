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
		ZAPPER,
		SUBZERO,
		UFO,
		THUNDER_SNAKE,
	};
	enum class EnemyState
	{
		ATTACK,
		DEAD,
		PATROLLING,
	};
}