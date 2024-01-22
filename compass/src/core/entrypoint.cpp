#include "entrypoint.h"
#include "application.h"

#include <memory>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    auto app = std::unique_ptr<Compass::Application>(Compass::CreateApplication());
    app->Run();
}