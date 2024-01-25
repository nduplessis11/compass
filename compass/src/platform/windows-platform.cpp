#include "windows-platform.h"

#include <windows.h>
#include <cstdint>
#include <vector>

namespace Compass {
// ReSharper disable once CppParameterMayBeConst
LRESULT CALLBACK WindowProc(HWND h_wnd, const UINT u_msg, const WPARAM w_param,
                            const LPARAM l_param) {
    switch (u_msg) {
        case WM_CLOSE:
            // TODO: Create event system. Fire event for application to quit
            DestroyWindow(h_wnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProcA(h_wnd, u_msg, w_param, l_param);
    }

    return 0;
}

bool WindowsPlatform::Initialize() {
    _hInstance = GetModuleHandleA(nullptr);

    WNDCLASSEXA windowClass{};

    windowClass.cbSize        = sizeof(WNDCLASSEXA);
    windowClass.style         = CS_DBLCLKS;
    windowClass.lpfnWndProc   = WindowProc;
    windowClass.cbClsExtra    = 0;
    windowClass.cbWndExtra    = 0;
    windowClass.hInstance     = _hInstance;
    windowClass.hIcon         = nullptr;
    windowClass.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    windowClass.hbrBackground = nullptr;
    windowClass.lpszMenuName  = nullptr;
    windowClass.lpszClassName = "compass_window_class";

    if (RegisterClassExA(&windowClass) == 0) {
        MessageBoxA(nullptr, "Window registration failed", "Error",
                    MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    constexpr uint16_t width  = 800;
    constexpr uint16_t height = 600;
    _hWnd = CreateWindowExA(0, "compass_window_class", "Compass",
                            WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                            CW_USEDEFAULT, width, height, nullptr, nullptr,
                            _hInstance, nullptr);

    if (_hWnd == nullptr) {
        MessageBoxA(nullptr, "Window Creation Failed!", "Error!",
                    MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    return true;
}

void WindowsPlatform::Shutdown() {
    // TODO: Handle _hWnd
    // TODO: Handle _hInstance

    // This is assuming WM_CLOSE called DestroyWindow(). Need to find a
    // way to handle this w/o calling DestroyWindow() twice on the same
    // hWnd
    _hWnd      = nullptr;
    _hInstance = nullptr;
}

void WindowsPlatform::WriteToConsole(const std::string_view text) {
    // TODO: Buffer output
    // TODO: Asynchronous writes

    // ReSharper disable once CppLocalVariableMayBeConst
    if (HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE)) {
        DWORD written = 0;
        WriteConsoleA(stdOut, text.data(), static_cast<DWORD>(text.size()),
                      &written, nullptr);
    }
}

[[nodiscard]] bool WindowsPlatform::PollEvents() const {
    MSG msg{};

    while (PeekMessageA(&msg, nullptr, 0U, 0U, PM_REMOVE) != 0) {
        if (msg.message == WM_QUIT) {
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return true;
}

}