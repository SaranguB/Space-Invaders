#include "../header/GraphicService.h"

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
}

sf::RenderWindow* GraphicService::CreateGameWindow()
{
	SetVideoMethod();
	return new sf::RenderWindow(*videoMode, gameWindowTitle);
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
