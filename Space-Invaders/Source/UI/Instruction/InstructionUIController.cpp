#include "../../Header/UI/Instruction/InstructionUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace UI
{
	namespace InstructionUI
	{
		using namespace Main;
		using namespace Global;

		using namespace UIElement;
		InstructionUIController::InstructionUIController()
		{
			menuButton = new ButtonView();
			instructionImage = new ImageView();
		}
		InstructionUIController::~InstructionUIController()
		{
			delete(menuButton);
			delete(instructionImage);
		}
		void InstructionUIController::Initialize()
		{
			InitialzeInstructionImage();
			InitializeButton();
			RegisterButtonCallback();

		}
		void InstructionUIController::Update()
		{
			instructionImage->Update();
			menuButton->Update();
		}
		void InstructionUIController::Render()
		{
			instructionImage->Render();
			menuButton->Render();
		}
		void InstructionUIController::InitialzeInstructionImage()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

			instructionImage->Initialize(Config::instruction_texture_path,
				gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));
		}
		void InstructionUIController::InitializeButton()
		{
			menuButton->Initialize("Menu Button", Config::menu_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(menuButtonXposition, menuButtonYposition));;;
		}

		void InstructionUIController::MenuButtonCallback()
		{
			GameService::SetGameState(GameState::MAIN_MENU);
		}

		void InstructionUIController::RegisterButtonCallback()
		{
			menuButton->RegisterCallBackFuntion
			(std::bind(&InstructionUIController::MenuButtonCallback, this));

		}
		void InstructionUIController::Show()
		{
		}

	}
}