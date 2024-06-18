#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;

		MainMenuUIController::MainMenuUIController()
		{
			gameWindow = nullptr;
		}

		void MainMenuUIController::Initialize()
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeBackgroundImage();

			InitializeButton();
		}

		void MainMenuUIController::InitializeBackgroundImage()
		{
			if (backgroundTexture.loadFromFile(backgroundTexturePath))
			{
				backgroundSprite.setTexture(backgroundTexture);
				ScaleBackroundImage();
			}
		}

		void MainMenuUIController::ScaleBackroundImage()
		{
			backgroundSprite.setScale(
				static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
				static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y);
		}

		void MainMenuUIController::InitializeButton()
		{
			if (LoadButtonTextureFromFile())
			{
				SetButtonSprites();
				ScaleAllButtons();
				PositionButtons();

			}
		}
		bool MainMenuUIController::LoadButtonTextureFromFile()
		{
			return playButtonTexture.loadFromFile(playButtonTexturePath) &&
				instructionsButtonTexture.loadFromFile(instructionsButtonTexturePath) &&
				quitButtonTexture.loadFromFile(quitButtonTexturePath);;
		}
		void MainMenuUIController::SetButtonSprites()
		{
			playButtonSprite.setTexture(playButtonTexture);
			instructionsButtonSprite.setTexture(instructionsButtonTexture);
			quitButtonSprite.setTexture(quitButtonTexture);
		}

		void MainMenuUIController::ScaleAllButtons()
		{
			ScaleButton(&playButtonSprite);
			ScaleButton(&instructionsButtonSprite);
			ScaleButton(&quitButtonSprite);
		}

		void MainMenuUIController::ScaleButton(sf::Sprite* buttonToScale)
		{
			buttonToScale->setScale(
				buttonWidth / buttonToScale->getTexture()->getSize().x,
				buttonHeight / buttonToScale->getTexture()->getSize().y
			);
		}

		void MainMenuUIController::PositionButtons()
		{
			float xPosition = (static_cast<float>(gameWindow->getSize().x) / 2) - buttonWidth / 2;
			playButtonSprite.setPosition({ xPosition, 500.f });
			instructionsButtonSprite.setPosition({ xPosition, 700.f });
			quitButtonSprite.setPosition({ xPosition, 900.f });
		}

		void MainMenuUIController::Update()
		{
		}

		void MainMenuUIController::Render()
		{
			gameWindow->draw(backgroundSprite);
			gameWindow->draw(playButtonSprite);
			gameWindow->draw(instructionsButtonSprite);
			gameWindow->draw(quitButtonSprite);
		}



	}
}