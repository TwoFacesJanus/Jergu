#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <intrin.h>
#pragma warning(disable: 4996)


std::string get_Ostype() {
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

	return OSTYPE;
}

std::string get_Cpu() {
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
	return CPUBrandString;
}

std::string get_Gpu() {
	// Get current graphical processor
	std::string Gpu;
	return Gpu;
}

std::string get_Ip() {

	return "Hi";


}

std::string get_Mem() {
	// Get current memory
	std::string Mem;
	return Mem;
}


void aboutMachine() {
	std::cout << "OS: " << get_Ostype() << std::endl;
	std::cout << "CPU: " << get_Cpu() << std::endl;
}