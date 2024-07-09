#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/Main Menu/MainMenuUIController.h"
#include<iostream>

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;
		using namespace Sound;
		using namespace UIElement;

		MainMenuUIController::MainMenuUIController()
		{
			CreateButton();
			CreateImage();
		}

		MainMenuUIController::~MainMenuUIController()
		{
			Destroy();
		}

		void MainMenuUIController::Destroy()
		{
			delete(playButton);
			delete(instructionButton);
			delete(quitButton);
			delete(backgroundImage);
		}

		void MainMenuUIController::CreateImage()
		{
			backgroundImage = new ImageView();
		}

		void MainMenuUIController::CreateButton()
		{
			playButton = new ButtonView();
			instructionButton = new ButtonView();
			quitButton = new ButtonView();
		}

		void MainMenuUIController::InitializeBackgroundImage()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			
			backgroundImage->Initialize(Config::background_texture_path, 
				gameWindow->getSize().x,gameWindow->getSize().y,sf::Vector2f(0,0));
			backgroundImage->SetImageAlpha(backgroundAlpha);
		}


		void MainMenuUIController::Initialize()
		{
			InitializeBackgroundImage();
			InitializeButton();
			RegisterButtonCallback();
			
		}

		void MainMenuUIController::InitializeButton()
		{
			playButton->Initialize("Play Button", Config::play_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(0, playButtonYposition));

			instructionButton->Initialize("Instruction Button", Config::instructions_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(0, instructionButtonYPosition));

			quitButton->Initialize("Quit Button", Config::quit_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(0, quitButtonYPosition));

			playButton->SetCentreAligned();
			instructionButton->SetCentreAligned();
			quitButton->SetCentreAligned();
		}


		void MainMenuUIController::PlayeButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
			GameService::SetGameState(GameState::GAMEPLAY);
			ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
		}

		void MainMenuUIController::InstructionButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);

		}

		void MainMenuUIController::QuitButtonCallback()
		{
			ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->close();
		}

		

		void MainMenuUIController::RegisterButtonCallback()
		{
			playButton->RegisterCallBackFuntion
			(std::bind(&MainMenuUIController::PlayeButtonCallback, this));

			instructionButton->RegisterCallBackFuntion
			(std::bind(&MainMenuUIController::InstructionButtonCallback, this));

			quitButton->RegisterCallBackFuntion(std::bind(&MainMenuUIController::QuitButtonCallback, this));
		}

		void MainMenuUIController::Update()
		{
			printf("update");
			backgroundImage->Update();
			playButton->Update();
			instructionButton->Update();
			quitButton->Update();


		}

		void MainMenuUIController::Render()
		{
			//printf("und");
			backgroundImage->Render();
			playButton->Render();
			instructionButton->Render();
			quitButton->Render();


		}

		void MainMenuUIController::Show()
		{
			printf("show und");

			backgroundImage->Show();
			playButton->Show();
			quitButton->Show();
			instructionButton->Show();

			ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
		}

		/* void MainMenuUIController::ProcessButtonInteractions()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));


			if (ClickedButton(&playButtonSprite, mousePosition))
			{
				//std::cout << "ok";
				GameService::SetGameState(GameState::GAMEPLAY);
				ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
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
		}*/


	}
}