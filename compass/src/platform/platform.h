#pragma once

#include <string_view>

namespace Compass {
class IPlatform {
  public:
         IPlatform()                                 = default;
         IPlatform(const IPlatform &)                = delete;
         IPlatform(IPlatform &&)                     = delete;
    auto operator=(const IPlatform &) -> IPlatform & = delete;
    auto operator=(IPlatform &&) -> IPlatform      & = delete;

    virtual ~IPlatform() = 0;

    virtual auto               Initialize() -> bool                  = 0;
    virtual void               Shutdown()                            = 0;
    [[nodiscard]] virtual auto PollEvents() const -> bool            = 0;
    virtual void               WriteToConsole(std::string_view text) = 0;
};
}