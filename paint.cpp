#include "paint.h"

void paint(HWND hWnd, HDC deviceContext)
{
	if(!done && myApi.dataExists)
	{
		//GetWindowRect(hWnd, &windowRect);
		memset(myApi.data, 255, 4 * myApi.numPixels);
		int i;
		for(i = 0; i < myApi.height; i++)
		{
			memset(myApi.data + i * myApi.width * 4, i * 255 / myApi.height, 4 * myApi.width);
		}
		myApi.refreshScreen();
	}
}