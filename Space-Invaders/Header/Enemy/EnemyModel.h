#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy
{

	enum class MovementDirection;
	enum class EnemyType;
	enum class EnemyState;

	class EnemyModel
	{


	private:
		sf::Vector2f referencePosition =sf::Vector2f(50.f,50.f );
		sf::Vector2f enemyPosition;
		MovementDirection  movementDirection;
		EnemyType enemyType;
		EnemyState enemyState;
		



	public:
		EnemyModel(EnemyType type);
		~EnemyModel();

		void Initialize();

		const float enemyMovementSpeed = 200.f;
		const float verticalTravelDistance = 100.0f;

		const sf::Vector2f LeftMostPosition = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f RightMostPosition = sf::Vector2f(1800.f, 950.f);


		sf::Vector2f GetEnemyPosition();
		void SetEnemyPosition(sf:: Vector2f position);

		sf::Vector2f GetReferencePosition();
		void SetReferencePosition(sf::Vector2f position);

		MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection direction);

		EnemyState GetEnemyState();
		void SetEnemyState(EnemyState state);

		EnemyType GetEnemyType();
		void SetEnemyType(EnemyType type);
		

	};
}
