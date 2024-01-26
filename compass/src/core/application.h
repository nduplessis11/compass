#pragma once
#include <complex>

namespace Compass {
class Application {
  public:
         Application()                                   = default;
         Application(const Application &)                = delete;
         Application(Application &&)                     = delete;
    auto operator=(const Application &) -> Application & = delete;
    auto operator=(Application &&) -> Application      & = delete;

    virtual ~Application() = default;

    void Run();

  private:
    bool _isRunning = false;
};

// To be defined in client
extern auto CreateApplication() -> std::unique_ptr<Application>;
}