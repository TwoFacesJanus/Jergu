#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <intrin.h>
#include <dxgi.h>
#include <windows.h>
#pragma comment (lib, "dxgi.lib")
#pragma warning(disable: 4996)

void get_Ostype() {
	char* ostype = getenv("OSTYPE");
	std::string OSTYPE;

	if (ostype == NULL) {
		ostype = getenv("windir");
		if (ostype != NULL)
			OSTYPE = "Windows";
	}
	else {

		if (strcmp(ostype, "linux") == 0)
			OSTYPE = "Linux";
		else if (strcmp(ostype, "darwin") == 0)
			OSTYPE = "Darwin";
	}
	std::cout << "OS  => " << OSTYPE << std::endl;
}

void get_Cpu() {
	int CPUInfo[4] = { -1 };
	__cpuid(CPUInfo, 0x80000000);
	unsigned int nExIds = CPUInfo[0];
	char CPUBrandString[0x40] = { 0 };

	for (unsigned int i = 0x80000000; i <= nExIds; i++) {
		__cpuid(CPUInfo, i);

		if (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		
		else if (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		
		else if (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
		
	}
	std::cout << "CPU => " << CPUBrandString << std::endl;
}

void get_Gpu() {
	IDXGIFactory1* pFactory;
	HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)(&pFactory));
	int AdapterNumber = 0;
	IDXGIAdapter1* Adapter;
	while (pFactory->EnumAdapters1(AdapterNumber++, &Adapter) != DXGI_ERROR_NOT_FOUND) {
		DXGI_ADAPTER_DESC1 Desc;
		Adapter->GetDesc1(&Desc);
		wprintf(L"GPU => %s\n", Desc.Description);
		Adapter->Release();
	}
	pFactory->Release();
}

void get_Ram() {
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	std::cout << "RAM => " << (float)statex.ullTotalPhys / (1024 * 1024 * 1024) << std::endl;
}
