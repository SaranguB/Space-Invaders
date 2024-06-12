#pragma once
#include "../header/GraphicService.h"


class ServiceLocator
{
private:

    GraphicService* graphicService;

    ServiceLocator(); 
    
  
    ~ServiceLocator(); 	

    
    void CreateServices(); 			
    void ClearAllServices(); 		

public:
    
    static ServiceLocator* GetInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

    void Initialize(); 			//	Initializes the ServiceLocator.
    void Update(); 				//	Updates all services.
    void Render(); 				//	Renders using the services.

    GraphicService* GetGraphicService();
    
};


