#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
	};
	class EnemyModel
	{


	private:
		sf::Vector2f referencePosition =sf::Vector2f(50.f,50.f );
		sf::Vector2f enemyPosition;
		MovementDirection movementDirection;
		



	public:
		EnemyModel();
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
		

	};
}
