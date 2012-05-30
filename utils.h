/***
	Everything that is needed in all CPP files
***/
#ifndef _utils_h_
#define _utils_h_

#include <windows.h>
#include <windowsx.h>
template <class type>
void deleteMakeNull(type* arr);
struct POINT2D
{
	int x, y;
};

extern HDC deviceContext;
extern POINT2D mousePos;
extern char* pixelData;
extern RECT windowRect;
extern RECT clientRect;//the inner(drawable) side of the windows

LPWSTR charToLPWSTR(char* str, int size);

#endif