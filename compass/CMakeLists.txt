# List of source files
set(SRC_FILES
    "src/application.cpp"
)

# List of header files
set(HDR_FILES
    "src/defines.h"
    "include/compass.h"
    "src/application.h"
    "src/entry-point.h"
)

add_library(compass STATIC ${SRC_FILES} ${HDR_FILES})

# Targets linked to compass are not linked to PRIVATE
# Targets linked to compass are vicariously linked to PUBLIC
target_include_directories(compass
    PUBLIC "include"
    PUBLIC "${PROJECT_BINARY_DIR}"
)