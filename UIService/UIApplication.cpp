#include "UIApplication.h"

namespace {
	UIApplication * gApp = nullptr;
};

UIApplication::UIApplication()
{
	if(gApp!=nullptr)
		throw std::runtime_error("Too More UIApplication Instance!");

	gApp = this;	
}

UIApplication::~UIApplication()
{

}

void UIApplication::DoMessageLoop()
{

}

int UIApplication::StatusCode()
{
	return 0;
}
