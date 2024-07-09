#pragma once
#include "../../Header/UI/Interface/IUIcontroller.h"
#include "../../Header/UI/UIElement/AnimatedImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIcontroller
		{

		private:
			const float logoAnimationDuration = 2.0f;
			const float logoWidth = 600.f;
			const float logoHeight = 134.f;

			UIElement::AnimatedImageView* outscalLogoView;

			void InitialiseOutscalLogo();
			void FadeOutAnimationCallback();
			void FadeInAnimationCallback();
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
