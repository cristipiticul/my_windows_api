#include "window_class.h"

wnd::wnd(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM), LPCWSTR className)
{
	wnd_init(hInstance, WndProc, className);
}
void wnd::wnd_init(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM), LPCWSTR className)
{
	if(hInstance == NULL)
		return;
	window.cbSize	= sizeof(WNDCLASSEX);
	window.style	= 0;
	window.lpfnWndProc	= WndProc;
	window.cbClsExtra	= 0;
	window.cbWndExtra	= 0;
	window.hInstance	= hInstance;
	window.hIcon	= LoadIcon(NULL, IDI_APPLICATION);
	window.hCursor	= LoadCursor(NULL, IDC_ARROW);
	window.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	window.lpszMenuName	= NULL;
	window.lpszClassName	= className;
	window.hIconSm	= LoadIcon(NULL, IDI_APPLICATION);
	//width		= defaultWidth;
	//height	= defaultHeight;
}
void wnd::reg()
{
	if(!RegisterClassEx(&window))
		MessageBox(NULL, (LPCWSTR)L"Window Registration Failed!", (LPCWSTR)L"Error!", MB_ICONEXCLAMATION | MB_OK);
}
void wnd::create(LPCWSTR windowName)
{
	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, window.lpszClassName, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, window.hInstance, NULL);
	if(hWnd == NULL)
		MessageBox(NULL, (LPCWSTR)L"Window Creation Failed!", (LPCWSTR)L"Error!", MB_ICONEXCLAMATION | MB_OK);
}
void wnd::show(int nCmdShow)
{
	ShowWindow(hWnd, nCmdShow);
}
void wnd::update()
{
	UpdateWindow(hWnd);
}
void wnd::updateScreen()
{
}