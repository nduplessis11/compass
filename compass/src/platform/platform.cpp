#include "platform.h"

namespace Compass {
// The linker needs this for pure virtual destructors
IPlatform::~IPlatform() = default;
}