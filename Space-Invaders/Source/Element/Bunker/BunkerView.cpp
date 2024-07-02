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
		void BunkerView::CreateUIElement()
		{
			bunkerImage = new ImageView();
		}
		void BunkerView::Initialize(BunkerController* controller)
		{
			bunkerController = controller;
			InitializeImage();
		}
		void BunkerView::InitializeImage()
		{
			bunkerImage->Initialize(Config::bunker_texture_path, bunkerWidth, bunkerHeight,
				bunkerController->GetBunkerPosition());

		}



		void BunkerView::Update()
		{
			bunkerImage->Update();
		}
		void BunkerView::Render()
		{
			bunkerImage->Render();
		}
	}
}