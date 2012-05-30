#include <stdio.h>
FILE *out;
#include "utils.h"

#include "windows_api.h"
#include "paint.h"
#include "callback_func.h"
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	fopen_s(&out, "log.txt", "w");
	myApi.api_init(hInstance);
	myApi.getMessageLoop();
	fclose(out);

	return 0;
}