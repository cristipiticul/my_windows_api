#ifndef _windows_api_
#define _windows_api_

#include "utils.h"
#include "window_class.h"

#define SendPaintMessage PostMessage(hWnd, WM_PRINT, (WPARAM)deviceContext, PRF_CHECKVISIBLE)

void paint(HWND, HDC);
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern bool done;

class api: public wnd
{
public:
	api();
	api(HINSTANCE hInstance);
	void api_init(HINSTANCE hInstance);
	void remakeBackBuffer();
	void refreshScreen();
	void getMessageLoop();
	~api();

	//char **pointerToData;
	bool dataExists;
	char *data;
	HBITMAP	back_buffer;
	HDC		DC_back_buffer;
	int numPixels;
	HDC hDC;
	bool remaking;
};
extern api myApi;

#endif