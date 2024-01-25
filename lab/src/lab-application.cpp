#include <compass.h>

class LabApplication final : public Compass::Application {
  public:
                    LabApplication()                       = default;
                    LabApplication(const LabApplication &) = delete;
                    LabApplication(LabApplication &&)      = delete;
    LabApplication &operator=(const LabApplication &)      = delete;
    LabApplication &operator=(LabApplication &&)           = delete;

    ~LabApplication() override = default;
};

std::unique_ptr<Compass::Application> Compass::CreateApplication() {
    return std::make_unique<LabApplication>();
}
