#include "../../Header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        ShieldController::ShieldController(PowerupType type) : PowerupController(type)
        {
        }
        ShieldController::~ShieldController()
        {
        }
        void ShieldController::OnCollected()
        {
        }
        void ShieldController::ApplyPowerup()
        {
            Global::ServiceLocator::GetInstance()->GetPlayerService()->EnableShield();
        }
    }
}
