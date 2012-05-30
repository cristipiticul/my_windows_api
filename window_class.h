#ifndef _windowClass_
#define _windowClass_
#define defaultWidth	800
#define defaultHeight	600
#include <windows.h>


class wnd
{
public:
	wnd(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM), LPCWSTR className);
	void wnd_init(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM), LPCWSTR className);
	void reg();
	void create(LPCWSTR windowName);
	void show(int nCmdShow);
	void update();
	void updateScreen();


	WNDCLASSEX	window;
	HWND	hWnd;
	int	width, height;
	friend class api;
};

#endif