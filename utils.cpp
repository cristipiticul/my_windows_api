#include "utils.h"

HDC deviceContext;
POINT2D mousePos;
char* pixelData;
RECT windowRect;
RECT clientRect;//the inner(drawable) side of the windows

inline void deleteMakeNull(void* arr)
{
	delete[] arr;
	arr	= NULL;
}

LPWSTR charToLPWSTR(char* str, int size)
{
	if(size >= 50)
		MessageBox(NULL, (LPCWSTR)L"String size too big! Check \"charToLPWSTR\"!", (LPCWSTR)L"WARNING", MB_ICONEXCLAMATION | MB_OK);
	wchar_t *wstr = new wchar_t[50];
	mbstowcs(wstr, str, 50);
	return (LPWSTR)wstr;
}