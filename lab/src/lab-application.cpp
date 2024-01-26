#include <compass.h>

class LabApplication final : public Compass::Application {
  public:
         LabApplication()                                      = default;
         LabApplication(const LabApplication &)                = delete;
         LabApplication(LabApplication &&)                     = delete;
    auto operator=(const LabApplication &) -> LabApplication & = delete;
    auto operator=(LabApplication &&) -> LabApplication      & = delete;

    ~LabApplication() override = default;
};

auto Compass::CreateApplication() -> std::unique_ptr<Application> {
    return std::make_unique<LabApplication>();
}
