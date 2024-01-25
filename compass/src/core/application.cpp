#include "application.h"
#include <memory>
#include "../platform/windows-platform.h"

namespace Compass {
void Application::Run() {
    const auto pPlatform = std::make_unique<WindowsPlatform>();
    pPlatform->Initialize();

    _isRunning = true;
    while (_isRunning) {
        if (!pPlatform->PollEvents()) {
            _isRunning = false;
        }

        constexpr uint32_t sleepTimeMilsecs = 10;
        Sleep(sleepTimeMilsecs);
    }
    pPlatform->Shutdown();
}
}