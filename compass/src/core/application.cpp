#include "application.h"
#include "../platform/windows-platform.h"
#include <memory>

namespace Compass {
    void Application::Run() {
        const auto pPlatform = std::make_unique<Compass::WindowsPlatform>();
        pPlatform->Initialize();

        _isRunning = true;
        while (_isRunning){
            if (!pPlatform->PollEvents()) {
                _isRunning = false;
            }

            constexpr uint32_t SLEEP_TIME_MILSCNDS = 10;
            Sleep(SLEEP_TIME_MILSCNDS);
        }
        pPlatform->Shutdown();
    }
}