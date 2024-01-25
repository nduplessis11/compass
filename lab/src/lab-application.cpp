#include <compass.h>
#include <gsl/gsl>

class LabApplication final : public Compass::Application {
  public:
                    LabApplication()                       = default;
                    LabApplication(const LabApplication &) = delete;
                    LabApplication(LabApplication &&)      = delete;
    LabApplication &operator=(const LabApplication &)      = delete;
    LabApplication &operator=(LabApplication &&)           = delete;

    ~LabApplication() override = default;
};

gsl::owner<Compass::Application *> Compass::CreateApplication() {
    return new LabApplication();
}
