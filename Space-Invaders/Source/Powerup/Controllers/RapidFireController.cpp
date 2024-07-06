#include "../../Header/Powerup/Controllers/RapidFireController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        Powerup::Controller::RapidFireController::RapidFireController(PowerupType type) : PowerupController(type)
        {
        }
        RapidFireController::~RapidFireController()
        {
        }
        void RapidFireController::OnCollected()
        {
        }
        void RapidFireController::ApplyPowerup()
        {
            Global::ServiceLocator::GetInstance()->GetPlayerService()->EnableRapidFire();
        }
    }
}
