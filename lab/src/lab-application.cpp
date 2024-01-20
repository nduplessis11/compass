#include <compass.h>

class LabApplication : public Compass::Application {
public:
	LabApplication() {}

	~LabApplication() {}
};

Compass::Application *Compass::CreateApplication() {
	return new LabApplication();
}
