#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Player/PlayerModel.h"

namespace UI
{
	namespace GameplayUI
	{

		using namespace Main;
		using namespace Sound;
		using namespace Global;
		using namespace Player;
		using namespace UI::UIElement;


		GameplayUIController::GameplayUIController()
		{
			CreateUIElement();
		}

		GameplayUIController::~GameplayUIController()
		{
			Destroy();
		}

		void GameplayUIController::Destroy()
		{
			delete(playerImage);
			delete(enemiesKilledText);
		}

		void GameplayUIController::CreateUIElement()
		{
			playerImage = new ImageView();
			enemiesKilledText = new TextView();
		}

		void GameplayUIController::Initialize()
		{
			InitializeImage();
			InitializeText();
		}

		void GameplayUIController::InitializeImage()
		{
			playerImage->Initialize(Config::player_texture_path,
				playerSpriteWidth, playerSpriteHeight, sf::Vector2f(0, 0));

		}

		void GameplayUIController::InitializeText()
		{
			sf::String enemiesKilledString = "Enemies Killed : 0";

			enemiesKilledText->Initialize(enemiesKilledString,
				sf::Vector2f(enemiesKilledTextXPosition, textYPosition),
				FontType::BUBBLE_BOBBLE, fontSize, textColor);
		}


		void GameplayUIController::UpdateEnemiesKilledText()
		{
			sf::String enemiesKilledString = "Enemies Killed :" + std::to_string(PlayerModel::enemiesKilled);
			enemiesKilledText->setText(enemiesKilledString);
		}

		void GameplayUIController::DrawplayerLives()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

			for (int i = 0;i < PlayerModel::playerLives;i++)
			{
				playerImage->SetPosition(sf::Vector2f(playerLivesXOffset -
					(i * playerLivesSpacing), playerLivesYOffset));
				playerImage->Render();
			}
		}

		void GameplayUIController::Update()
		{
			UpdateEnemiesKilledText();
		}

		void GameplayUIController::Render()
		{
			printf("Render");
			enemiesKilledText->Render();
			DrawplayerLives();
		}

		void GameplayUIController::Show()
		{
		}

	}
}