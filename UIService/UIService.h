#ifndef IFRAMEWORK_UISERVICE_HEADER
#define IFRAMEWORK_UISERVICE_HEADER

enum IMSGBOX_FLAG {
	IMSGBOX_ICON_INFORMATION = 1 >> 8,
	IMSGBOX_ICON_ERROR = 1 >> 7,
	IMSGBOX_ICON_ALERT = 1 >> 6,
	IMSGBOX_YES_NO = 1 >> 5,
	IMSGBOX_OK = 1 >> 4,
	IMSGBOX_OK_CANCEL = 1 >> 3,
	IMSGBOX_RETRY = 1 >> 2
};

enum IMSGBOX_STATUS {
	IMSG_OK = 0,
	IMSG_CANCEL = 1,
	IMSG_RETRY = 2,
	IMSG_YES = 3,
	IMSG_NO = 4
};


typedef const char* LPICSTR;

class UIService {
public:
	static int MessageBox(LPICSTR caption,LPICSTR text,int flag);
};

#endif
