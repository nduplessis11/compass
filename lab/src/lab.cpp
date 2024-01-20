// lab.cpp : Source file for your target.
//

#include <iostream>

#include "lab.h"
#include "compass.h"

int main()
{
	std::cout 
		<< "Compass started! (" 
		<< PROJECT_VERSION_MAJOR 
		<< "." << PROJECT_VERSION_MINOR 
		<< "." << PROJECT_VERSION_PATCH 
		<< ")\n";
	return 0;
}
