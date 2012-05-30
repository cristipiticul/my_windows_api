#include "OpenCL_header.h"

void clSources::addSource(char* fileName)
{
		FILE *in;
		fopen_s(&in, fileName, "r");
		codeStrings[numOfSources] = new char[4096];
		size[numOfSources] = fread(codeStrings[numOfSources], sizeof(char), 4096, in);
		if(!feof(in))
			MessageBoxW(NULL, (LPCWSTR)L"File source bigger than 4096 characters!", (LPCWSTR)L"ERROR!", MB_ICONERROR | MB_OK);
		numOfSources++;
}

openclController::openclController()
{
		error		= clGetPlatformIDs(1, &platformID, NULL);
		if(error)
			MessageBoxW(NULL, (LPCWSTR)L"ERROR clGetPlatformIDs!", (LPCWSTR)L"ERROR!", MB_ICONERROR | MB_OK);

		clGetDeviceIDs(platformID, CL_DEVICE_TYPE_GPU, 1, &deviceID, NULL);
		if(platformID == NULL)
			MessageBoxW(NULL, (LPCWSTR)L"ERROR clGetDeviceIDs!", (LPCWSTR)L"ERROR!", MB_ICONERROR | MB_OK);

		hContext	= clCreateContext(0, 1, &deviceID, NULL, NULL, &error);
		if(error)
			MessageBoxW(NULL, (LPCWSTR)L"ERROR clCreateContext", (LPCWSTR)L"ERROR!", MB_ICONERROR | MB_OK);

		hQueue		= clCreateCommandQueue(hContext, deviceID, 0, &error);
		if(error)
			MessageBoxW(NULL, (LPCWSTR)L"ERROR clCreateCommandQueue!", (LPCWSTR)L"ERROR!", MB_ICONERROR | MB_OK);

		hProgram	= clCreateProgramWithSource(hContext, sources.numOfSources, (const char**)sources.codeStrings, sources.size, &error);
		if(error)
			MessageBoxW(NULL, (LPCWSTR)L"ERROR clCreateProgramWithSource!", (LPCWSTR)L"ERROR!", MB_ICONERROR | MB_OK);

		clBuildProgram(hProgram, 0, 0, 0, 0, 0);
}