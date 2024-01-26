#include "entrypoint.h"
#include "application.h"

#include <memory>

auto main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) -> int {
    const auto app = Compass::CreateApplication();
    app->Run();

    return 0;
}