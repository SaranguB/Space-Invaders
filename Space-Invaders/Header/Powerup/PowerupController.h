#pragma once
#include "../../Header/Collectible/Collectible.h"
#include "../../Header/Collision/ICollider.h"

namespace Powerup
{
	enum class PowerupType;
	class PowerupModel;
	class PowerupView;

	class PowerupController : public Collectible::ICollectible, public Collision::ICollider
	{

	protected:
		PowerupModel* powerupModel;
		PowerupView* powerupView;

		void UpdatePowerPosition();
		void HandleOutOfBonds();

	public:
		PowerupController(PowerupType type);
		~PowerupController() override;

		void Initialize(sf::Vector2f position) override;
		void Update() override;
		void Render() override;

		void OnCollected() override;

		PowerupType GetPowerupType();
		sf::Vector2f GetCollectiblePosition() override;	
		virtual void ApplyPowerup() = 0;

		const sf::Sprite& GetColliderSprite() override; 
		void OnCollision(ICollider* otherCollider) override;

	};
}
