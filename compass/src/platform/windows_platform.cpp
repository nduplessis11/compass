#include "platform.h"

#include <windows.h>

namespace Compass {
    class WindowsPlatform final : public IPlatform {
    public:
        void Initialize() final {
            _hInstance = GetModuleHandleA(CURRENT_MODULE_HANDLE);

            WNDCLASSA windowClass;

            windowClass.style = CS_DBLCLKS;
            windowClass.lpfnWndProc = window_procedure;
            windowClass.cbClsExtra = 0;
            windowClass.cbWndExtra = 0;
            windowClass.hInstance = _hInstance;
            windowClass.hIcon = nullptr;
            windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
            windowClass.hbrBackground = nullptr;
            windowClass.lpszMenuName = nullptr;
            windowClass.lpszClassName = "Compass";

            RegisterClassA(&windowClass);
        }

        void Shutdown() final {

        }

        void PollEvents() const final {

        }

    private:
        static LRESULT CALLBACK window_procedure(HWND hWnd, UINT message,
                                         WPARAM wParam, LPARAM lParam) {

            return 0;
        }

        static constexpr LPCSTR CURRENT_MODULE_HANDLE = nullptr;
        HINSTANCE _hInstance;
        HWND _hWnd;
    };
}