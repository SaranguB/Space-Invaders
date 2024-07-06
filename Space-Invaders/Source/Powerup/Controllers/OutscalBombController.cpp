#include "../../Header/Powerup/Controllers/OutscalBombController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        OutscalBombController::OutscalBombController(PowerupType type) : PowerupController(type)
        {
        }
        OutscalBombController::~OutscalBombController()
        {
        }
        void OutscalBombController::OnCollected()
        {
        }
        void OutscalBombController::ApplyPowerup()
        {
            Global::ServiceLocator::GetInstance()->GetEnemyService()->Reset();
        }
    }
}