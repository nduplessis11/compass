#include "platform.h"

#include <windows.h>
#include <cstdint>

namespace Compass {
    class WindowsPlatform final : public IPlatform {
    public:
        bool Initialize() final;
        void Shutdown() final;
        [[nodiscard]] bool PollEvents() const final;

    private:
        HINSTANCE _hInstance = nullptr;
        HWND _hWnd = nullptr;
    };
}