#include "../../Header/Graphic/GraphicService.h"


namespace Graphic
{


	GraphicService::GraphicService()
	{
		gameWindow = nullptr;
		videoMode = nullptr;
	}

	GraphicService::~GraphicService()
	{
		OnDestroy();

	}

	void GraphicService::Initialize()
	{
		gameWindow = CreateGameWindow();
		gameWindow->setFramerateLimit(frameRate);
	}

	sf::RenderWindow* GraphicService::CreateGameWindow()
	{
		SetVideoMethod();
		return new sf::RenderWindow(*videoMode, gameWindowTitle, sf::Style::Fullscreen);
	}


	void GraphicService::SetVideoMethod()
	{
		videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);

	}

	void GraphicService::OnDestroy()
	{
		delete(videoMode);
		delete(gameWindow);
	}

	void GraphicService::Update()
	{
	}

	void GraphicService::Render()
	{
	}



	bool GraphicService::IsGameWindowOpen()
	{
		return gameWindow->isOpen();
	}

	sf::RenderWindow* GraphicService::GetGameWindow()
	{
		return gameWindow;
	}

	sf::Color GraphicService::GetWindowColor()
	{
		return windowColor;
	}
}
