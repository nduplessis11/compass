#include "application.h"

namespace Compass {
    void Application::Run() {
        _isRunning = true;
        while (_isRunning){}
    }
}