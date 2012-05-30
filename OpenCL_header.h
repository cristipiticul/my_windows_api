#ifndef _OpenCL_header_
#define _OpenCL_header_

#include <CL/opencl.h>
#include <windows.h>
#include <stdio.h>

class clSources
{
public:
	clSources()
	{
		numOfSources = 0;
	}
	void addSource(char* fileName);

	int numOfSources;
	char* codeStrings[10];
	size_t size[10];
};

class openclController
{
	openclController();

	cl_int 			error;
	cl_platform_id	platformID;
	cl_device_id	deviceID;
	cl_context		hContext;
	cl_command_queue	hQueue;
	cl_program		hProgram;
	cl_kernel		hKernel;
	clSources		sources;
};

#endif