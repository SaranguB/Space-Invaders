#pragma once


namespace UI
{
	namespace Interface
	{
		class IUIcontroller
		{
		public:
			virtual void Initialize() = 0;
			virtual void Update() = 0;
			virtual void Render() = 0;

			virtual void Show() = 0;

			virtual ~IUIcontroller() = 0;
		};

		inline IUIcontroller::~IUIcontroller() {}
	}
}