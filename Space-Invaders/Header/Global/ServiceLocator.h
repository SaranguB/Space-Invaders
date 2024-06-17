#pragma once
#include "../Graphic/GraphicService.h"
#include "../Event/EventService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"

namespace Global
{


	class ServiceLocator
	{
	private:

		Graphic::GraphicService* graphicService;
		Event::EventService* eventService;
		Player::PlayerService* playerService;
		Time::TimeService* timeService;

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
	};
}

