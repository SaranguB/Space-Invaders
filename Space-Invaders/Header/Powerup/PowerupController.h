#pragma once
#include "../../Header/Collectible/Collectible.h"

namespace Powerup
{
	enum class PowerupType;
	class PowerupModel;
	class PowerupView;

	class PowerupController : public Collectible::ICollectible
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

		PowerupType GetpowerupType();
		sf::Vector2f GetCollectiblePosition() override;	

	};
}
