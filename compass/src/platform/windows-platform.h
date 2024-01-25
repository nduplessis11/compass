#pragma once

#include "platform.h"

#include <windows.h>

namespace Compass {
class WindowsPlatform final : public IPlatform {
  public:
    bool               Initialize() override;
    void               Shutdown() override;
    void               WriteToConsole(std::string_view text) override;
    [[nodiscard]] bool PollEvents() const override;

  private:
    HINSTANCE _hInstance = nullptr;
    HWND      _hWnd      = nullptr;
};
}