#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
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
	// Get current processor
	std::string Cpu;
	return Cpu;
}

std::string get_Gpu() {
	// Get current graphical processor
	std::string Gpu;
	return Gpu;
}

std::string get_Ip() {
	// Get current ip address
	std::string Ip;
	return Ip;
}

std::string get_Mem() {
	// Get current memory
	std::string Mem;
	return Mem;
}


void aboutMachine() {
	std::cout << get_Ostype() << std::endl;


}