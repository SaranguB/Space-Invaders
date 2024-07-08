#include "../../Header/Powerup/Controllers/TrippleLaserController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Powerup
{
	namespace Controller
	{
		
		TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type)
		{
		}
		TrippleLaserController::~TrippleLaserController()
		{
		}
		void TrippleLaserController::Oncollected()
		{
		}
		void TrippleLaserController::ApplyPowerup()
		{
			Global::ServiceLocator::GetInstance()->GetPlayerService()->EnableTrippleLaser();
		}
	}
}