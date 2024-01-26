#pragma once

#include "platform.h"

#include <windows.h>

namespace Compass {
class WindowsPlatform final : public IPlatform {
  public:
    auto               Initialize() -> bool override;
    void               Shutdown() override;
    void               WriteToConsole(std::string_view text) override;
    [[nodiscard]] auto PollEvents() const -> bool override;

  private:
    HINSTANCE _hInstance = nullptr;
    HWND      _hWnd      = nullptr;
};
}