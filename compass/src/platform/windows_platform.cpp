#include "platform.h"

#include <windows.h>
#include <cstdint>

namespace Compass {
    class WindowsPlatform final : public IPlatform {
    public:
        bool Initialize() final {
            _hInstance = GetModuleHandleA(CURRENT_MODULE_HANDLE);

            WNDCLASSEXA windowClass{};

            windowClass.cbSize = sizeof(WNDCLASSEXA);
            windowClass.style = CS_DBLCLKS;
            windowClass.lpfnWndProc = window_procedure;
            windowClass.cbClsExtra = 0;
            windowClass.cbWndExtra = 0;
            windowClass.hInstance = _hInstance;
            windowClass.hIcon = nullptr;
            windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
            windowClass.hbrBackground = nullptr;
            windowClass.lpszMenuName = nullptr;
            windowClass.lpszClassName = "compass_window_class";

            if (RegisterClassExA(&windowClass) == 0) {
                MessageBoxA(nullptr, "Window registration failed", "Error", MB_ICONEXCLAMATION | MB_OK);
                return false;
            }

            const uint16_t WIDTH = 800;
            const uint16_t HEIGHT = 800;
            _hWnd = CreateWindowExA(0, "compass_window_class", "Compass",
                           WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                           CW_USEDEFAULT, WIDTH, HEIGHT,
                           nullptr, nullptr, _hInstance, nullptr);

            if (_hWnd == nullptr) {
                MessageBoxA(nullptr, "Window Creation Failed!", "Error!",
                            MB_ICONEXCLAMATION | MB_OK);
                return false;
            }

            return true;
        }

        void Shutdown() final {

        }

        void PollEvents() const final {

        }

    private:
        // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
        static LRESULT CALLBACK window_procedure(HWND hWnd, UINT message,
                                                 WPARAM wParam, LPARAM lParam) {
            
            LRESULT result = 0;

            switch (message)
            {
            case WM_CLOSE:
                // TODO: Set _isRunning to false
                PostQuitMessage(0);
                result = 0;
                break;

            default:
                result = DefWindowProcA(_hWnd, message, wParam, lParam);
            }
            return result;
        }

        static constexpr LPCSTR CURRENT_MODULE_HANDLE = nullptr;
        HINSTANCE _hInstance;
        static HWND _hWnd;
    };
}