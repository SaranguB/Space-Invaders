#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include<iostream>

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
			ProcessButtonInteractions();
		}

		void MainMenuUIController::Render()
		{
			gameWindow->draw(backgroundSprite);
			gameWindow->draw(playButtonSprite);
			gameWindow->draw(instructionsButtonSprite);
			gameWindow->draw(quitButtonSprite);
		}

		void MainMenuUIController::ProcessButtonInteractions()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

			if (ClickedButton(&playButtonSprite, mousePosition))
			{
				std::cout << "ok";

				GameService::SetGameState(GameState::GAMEPLAY);
			}
			if (ClickedButton(&quitButtonSprite, mousePosition))
			{

				gameWindow->close();
			}

			if (ClickedButton(&instructionsButtonSprite, mousePosition))
			{
				printf("clicked instructions");
			}

		}

		bool MainMenuUIController::ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
		{

			EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

			if (buttonSprite->getGlobalBounds().contains(mousePosition))
			{
				//std::cout << "jo";
			}
			if (eventService->PressedLeftMouseButton())
			{
				//std::cout << "also";
			}
			if (eventService->PressedLeftMouseButton() && buttonSprite->getGlobalBounds().contains(mousePosition)) 
			{
				//std::cout << "justalso";

				return eventService->PressedLeftMouseButton() && buttonSprite->getGlobalBounds().contains(mousePosition);
			}
		}


	}
}