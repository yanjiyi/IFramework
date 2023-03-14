#ifndef UIAPPLICATION_HEADER
#define UIAPPLICATION_HEADER

#include "IObject.h"

class UIApplication : public IObject {
	public:
		UIApplication();
		~UIApplication();

		static UIApplication* GetApp();

		virtual void DoInstance() = 0;

		void DoMessageLoop();

		int StatusCode();
};

#endif
