#pragma once
#include <string_view>

namespace Compass {

class ILogger {
  protected:
    ILogger() = default;

  public:
             ILogger(const ILogger &)   = delete;
             ILogger(ILogger &&)        = delete;
    ILogger &operator=(const ILogger &) = delete;
    ILogger &operator=(ILogger &&)      = delete;
    virtual ~ILogger()                  = 0;

    virtual void Info(std::string_view msg)  = 0;
    virtual void Debug(std::string_view msg) = 0;
    virtual void Warn(std::string_view msg)  = 0;
    virtual void Error(std::string_view msg) = 0;
    virtual void Fatal(std::string_view msg) = 0;
    virtual void Trace(std::string_view msg) = 0;
};

} // Compass
