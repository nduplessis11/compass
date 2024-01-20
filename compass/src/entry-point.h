#pragma once

#include "defines.h"
#include "application.h"

//#ifdef CMPS_PLATFORM_WINDOWS

extern Compass::Application *Compass::CreateApplication();

int main(int argc, char **argv)
{
	auto app = Compass::CreateApplication();
	app->Run();
	delete app;
}

//#endif