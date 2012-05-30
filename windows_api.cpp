#include "windows_api.h"

#define SendPaintMessage PostMessage(hWnd, WM_PRINT, (WPARAM)deviceContext, PRF_CHECKVISIBLE)

bool done = false;
api myApi;
void paint(HWND, HDC);
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

api::api(): wnd(NULL, NULL, NULL)
{
	dataExists	= false;
}
api::api(HINSTANCE hInstance): wnd(hInstance, WndProc, (LPCWSTR)L"myClass")
{
	api_init(hInstance);
}
void api::api_init(HINSTANCE hInstance)
{
	wnd_init(hInstance, WndProc, (LPCWSTR)L"myClass");
	reg();
	create((LPCWSTR)L"myWindow");
	show(1);
	update();
	GetWindowRect(hWnd, &windowRect);
	GetClientRect(hWnd, &clientRect);
	width	= clientRect.right	- clientRect.left;
	height	= clientRect.bottom	- clientRect.top;
	dataExists	= false;
	remaking	= false;
	hDC	= deviceContext	= GetDC(hWnd);
	remakeBackBuffer();
}
void api::remakeBackBuffer()
{
	if(remaking == true)
		return;
	remaking = true;
	numPixels	= width * height;
	if(dataExists)
	{
		delete[] data;
		//delete[] (*pointerToData);
	}
	//pointerToData	= new char*();
	//*pointerToData	= new char[4 * numPixels + 2];
	data		= new char[4 * numPixels];
	if(data == NULL)
	{
		MessageBox(NULL, (LPCWSTR)L"PIXEL DATA DOESN'T EXIST (windows_api.h, void remakeBackBuffer())", (LPCWSTR)L"ERROR", MB_OK);
		dataExists	= false;
	}
	DeleteObject(back_buffer);
	DeleteDC(DC_back_buffer);

	DC_back_buffer	= CreateCompatibleDC(hDC);
	back_buffer	= CreateCompatibleBitmap(hDC, width, height);
	dataExists	= true;
	remaking	= false;
	SendPaintMessage;
}
void api::refreshScreen()
{
	SetBitmapBits(back_buffer, 4 * numPixels, data);
	SelectObject(DC_back_buffer, back_buffer);
	BitBlt(hDC, 0, 0, width, height, DC_back_buffer, 0, 0, SRCCOPY);
}
void api::getMessageLoop()
{
	MSG msg;
	while(GetMessage(&msg, hWnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
api::~api()
{
	ReleaseDC(hWnd, hDC);
	if(dataExists)
		delete[] data;
	DeleteObject(back_buffer);
	DeleteDC(DC_back_buffer);
	DeleteDC(hDC);
}