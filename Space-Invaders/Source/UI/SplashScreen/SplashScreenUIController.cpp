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
			outscalLogoView = new AnimatedImageView();
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
			outscalLogoView->Update();
		}


		void SplashScreenUIController::FadeInAnimationCallback()
		{
			
			outscalLogoView->PlayAnimation(AnimationType::FADE_OUT,
				logoAnimationDuration, std::bind(&SplashScreenUIController::FadeOutAnimationCallback, this));
		}
		void SplashScreenUIController::FadeOutAnimationCallback()
		{

			ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
			GameService::SetGameState(GameState::MAIN_MENU);
		}

		void SplashScreenUIController::Render()
		{
			outscalLogoView->Render();
		}

		sf::Vector2f SplashScreenUIController::GetLogoPosition()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::
				GetInstance()->GetGraphicService()->GetGameWindow();

			float xPosition = (gameWindow->getSize().x - logoWidth) / 2.f;
			float yPosition = (gameWindow->getSize().y - logoHeight) / 2.f;

			return sf::Vector2f(xPosition, yPosition);
		}

		void SplashScreenUIController::Show()
		{
			outscalLogoView->PlayAnimation(AnimationType::FADE_IN, logoAnimationDuration,
				std::bind(&SplashScreenUIController::FadeInAnimationCallback, this));
		}
	}
}