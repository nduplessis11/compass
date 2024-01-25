#pragma once

#include "platform.h"

#include <windows.h>

namespace Compass {
    class WindowsPlatform final : public IPlatform {
    public:
        bool Initialize() final;
        void Shutdown() final;
        void WriteToConsole(std::string_view text) final;
        [[nodiscard]] bool PollEvents() const final;

    private:
        HINSTANCE _hInstance = nullptr;
        HWND _hWnd = nullptr;
    };
}