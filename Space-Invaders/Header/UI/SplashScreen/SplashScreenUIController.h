#pragma once
#include "../../Header/UI/Interface/IUIcontroller.h"
#include "../../Header/UI/UIElement/ImageView.h"
namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIcontroller
		{

		private:
			const float splashScreenDuration = 2.0f;
			float elapsedDuration = 0.0f;
			const float logoWidth = 600.f;
			const float logoHeight = 134.f;

			UIElement::ImageView* outscalLogoView;

			void InitialiseOutscalLogo();
			void UpdateTimer();
			void ShowMainMenu();
			sf::Vector2f GetLogoPosition();

		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void Initialize() override;
			void Render() override;
			void Update() override;
			void Show() override;

		};
	}
}
