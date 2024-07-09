#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphic/GraphicService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"


namespace UI
{
	namespace SplashScreen
	{
		using namespace Main;
		using namespace Graphic;
		using namespace Global;
		using namespace UIElement;
		using namespace Sound;

		SplashScreenUIController::SplashScreenUIController()
		{
			outscalLogoView = new ImageView();
		}

		SplashScreenUIController::~SplashScreenUIController()
		{
			delete(outscalLogoView);
		}

		void SplashScreenUIController::Initialize()
		{
			InitialiseOutscalLogo();
		}

		void SplashScreenUIController::InitialiseOutscalLogo()
		{
			sf::Vector2f position = GetLogoPosition();
			outscalLogoView->Initialize(Config::outscal_logo_texture_path, logoWidth, logoHeight, position);
		}

		void SplashScreenUIController::Update()
		{
			UpdateTimer();
			ShowMainMenu();
		}


		void SplashScreenUIController::UpdateTimer()
		{
			elapsedDuration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		}
		void SplashScreenUIController::ShowMainMenu()
		{
			if (elapsedDuration >= splashScreenDuration)
			{
				ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
				GameService::SetGameState(GameState::MAIN_MENU);
			}
		}

		void SplashScreenUIController::Render()
		{
			outscalLogoView->Render();
		}

		sf::Vector2f SplashScreenUIController::GetLogoPosition()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

			float xPosition = (gameWindow->getSize().x - logoWidth) / 2.f;
			float yPosition = (gameWindow->getSize().x - logoHeight) / 2.f;

			return sf::Vector2f(xPosition, yPosition);
		}

		void SplashScreenUIController::Show()
		{
		}
	}
}