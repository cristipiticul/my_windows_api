#include "callback_func.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_SIZE:
		myApi.width		= LOWORD(lParam);
		myApi.height	= HIWORD(lParam);
		myApi.remakeBackBuffer();
		break;
	case WM_QUIT:
		done = true;
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		PAINTSTRUCT ps;
		if(deviceContext == NULL)
		{
			deviceContext = BeginPaint(hWnd, &ps);
			paint(hWnd, deviceContext);
			EndPaint(hWnd, &ps);
		}
		else
			paint(hWnd, deviceContext);
		break;
	case WM_MOUSEMOVE:
		mousePos.x = GET_X_LPARAM(lParam);
		mousePos.y = GET_Y_LPARAM(lParam);
		SendPaintMessage;
		break;
	case WM_PRINT:
		paint(hWnd, (HDC)wParam);
		break;
	case WM_KEYDOWN:
		SendPaintMessage;
		break;
	case WM_MBUTTONDOWN:
		SendPaintMessage;
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}