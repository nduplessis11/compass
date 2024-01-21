#include <compass.h>

class LabApplication final : public Compass::Application {
public:
    LabApplication() = default;
    LabApplication(const LabApplication &) = delete;
    LabApplication(LabApplication &&) = delete;
    LabApplication &operator=(const LabApplication &) = delete;
    LabApplication &operator=(LabApplication &&) = delete;

    ~LabApplication() final = default;
};

Compass::Application *Compass::CreateApplication() {
	return new LabApplication();
}
