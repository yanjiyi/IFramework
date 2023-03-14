#include "UIService.h"
#include <GL/glew.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

int UIService::MessageBox(LPICSTR caption, LPICSTR text, int flag)
{
	Display* display = XOpenDisplay(NULL);
	int screen = DefaultScreen(display);
	return IMSGBOX_OK;
}
