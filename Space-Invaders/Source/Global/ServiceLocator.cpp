#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"


#include<iostream>

namespace Global
{
	using namespace Graphic;
	using namespace Event;
	using namespace Player;
	using namespace Time;
	using namespace UI;
	using namespace Main;
	using namespace Enemy;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;

	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		timeService = nullptr;
		uiService = nullptr;
		enemyService = nullptr;
		gameplayService = nullptr;
		elementService = nullptr;
		soundService = nullptr;
		bulletService = nullptr;
		powerupService = nullptr;
		CreateServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		ClearAllServices();
	}

	void ServiceLocator::CreateServices()
	{
		graphicService = new GraphicService();
		eventService = new EventService();
		playerService = new PlayerService();
		timeService = new TimeService();
		uiService = new UIService();
		enemyService = new EnemyService();
		gameplayService = new GameplayService();
		elementService = new ElementService();
		soundService = new SoundService();
		bulletService = new BulletService();
		powerupService = new PowerupService();
	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		graphicService = nullptr;
		delete(eventService);
		eventService = nullptr;
		delete(playerService);
		playerService = nullptr;
		delete(timeService);
		timeService = nullptr;
		delete(uiService);
		uiService = nullptr;
		delete(gameplayService);
		gameplayService = nullptr;
		delete(elementService);
		elementService = nullptr;
		delete(soundService);
		delete(bulletService);
		delete(powerupService);



	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::Initialize()
	{

		graphicService->Initialize();
		eventService->Initialize();
		playerService->Initialize();
		enemyService->Initialize();
		timeService->Initialize();
		uiService->Initialize();
		gameplayService->Initialize();
		elementService->Intialize();
		soundService->Initialize();
		bulletService->Initialize();
		powerupService->Initialize();


		//to initilize 
	}

	void ServiceLocator::Update()
	{
		//printf("hi");

		graphicService->Update();
		eventService->Update();
		timeService->Update();


		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			//printf("hi");
			playerService->Update();
			enemyService->Update();
			gameplayService->Update();
			elementService->Update();
			bulletService->Update();
			powerupService->Update();

		}


		uiService->Update();


		//std::cout << "hello";

		//to update
	}

	void ServiceLocator::Render()
	{
		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Render();
			playerService->Render();
			enemyService->Render();
			elementService->Render();
			bulletService->Render();
			powerupService->Render();



		}
		uiService->Render();

		// to render
	}

	GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicService;
	}

	EventService* ServiceLocator::GetEventService()
	{
		return eventService;
	}

	PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}

	TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}

	UI::UIService* ServiceLocator::GetUIService()
	{
		return uiService;
	}

	Enemy::EnemyService* ServiceLocator::GetEnemyService()
	{
		return enemyService;
	}

	Gameplay::GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}

	Sound::SoundService* ServiceLocator::GetSoundService()
	{
		return soundService;
	}

	Bullet::BulletService* ServiceLocator::GetBulletServices()
	{
		return bulletService;
	}

	Powerup::PowerupService* ServiceLocator::GetPowerupService()
	{
		return powerupService;
	}


}
