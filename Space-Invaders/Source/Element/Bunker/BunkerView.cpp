#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/Config.h"

namespace Element
{
	namespace Bunker
	{
		using namespace UI::UIElement;
		using namespace Global;
		BunkerView::BunkerView()
		{
			CreateUIElement();
		}
		BunkerView::~BunkerView()
		{
			Destroy();
		}
		void BunkerView::Initialize(BunkerController* controller)
		{
			bunkerController = controller;
			InitializeImage();
		}
		void BunkerView::InitializeImage()
		{
			
		}

		

		void BunkerView::Update()
		{
		}
		void BunkerView::Render()
		{
		}
	}
}