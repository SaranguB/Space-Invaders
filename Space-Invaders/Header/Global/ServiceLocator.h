#pragma once
#include "../Graphic/GraphicService.h"
#include "../Event/EventService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService.h"
#include "../Enemy/EnemyService.h"
#include "../Gameplay/GameplayService.h"
#include "../../Header/Element/ElementService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Powerup/PowerupService.h"


namespace Global
{


	class ServiceLocator
	{
	private:

		Graphic::GraphicService* graphicService;
		Event::EventService* eventService;
		Player::PlayerService* playerService;
		Time::TimeService* timeService;
		UI::UIService* uiService;
		Enemy::EnemyService* enemyService;
		Gameplay::GameplayService* gameplayService;
		Element::ElementService* elementService;
		Sound::SoundService* soundService;
		Bullet::BulletService* bulletService;
		Powerup::PowerupService* powerupService;

		ServiceLocator();


		~ServiceLocator();


		void CreateServices();
		void ClearAllServices();

	public:

		static ServiceLocator* GetInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

		void Initialize(); 			//	Initializes the ServiceLocator.
		void Update(); 				//	Updates all services.
		void Render(); 				//	Renders using the services.

		Graphic::GraphicService* GetGraphicService();
		Event::EventService* GetEventService();
		Player::PlayerService* GetPlayerService();
		Time::TimeService* GetTimeService();
		UI::UIService* GetUIService();
		Enemy::EnemyService* GetEnemyService();
		Gameplay::GameplayService* GetGameplayService();
		Sound::SoundService* GetSoundService();
		Bullet::BulletService* GetBulletServices();
		Powerup::PowerupService* GetPowerupService();
	};
}

