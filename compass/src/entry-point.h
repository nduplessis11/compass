#pragma once

#include "application.h"
#include <memory>

int main(int argc, char **argv)
{
    auto app = std::unique_ptr<Compass::Application>(Compass::CreateApplication());
	app->Run();
}
