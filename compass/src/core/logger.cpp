#include "logger.h"

#include <memory>

#include "../platform/platform.h"

namespace Compass {
class IPlatform;
class Logger final : public ILogger {
    explicit Logger(const std::shared_ptr<IPlatform> &platform)
      : _platform(platform) {
    }

  public:
    void Info(const std::string_view msg) override {
        _platform->WriteToConsole(msg);
    }
    void Debug(std::string_view msg) override;
    void Warn(std::string_view msg) override;
    void Error(std::string_view msg) override;
    void Fatal(std::string_view msg) override;
    void Trace(std::string_view msg) override;

    static Logger &GetInstance(const std::shared_ptr<IPlatform> &platform) {
        static Logger instance(platform);
        return instance;
    }

  private:
    std::shared_ptr<IPlatform> _platform;
};
} // Compass