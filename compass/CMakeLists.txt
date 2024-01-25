# List of source files
set(SRC_FILES
        "src/core/application.cpp"
        "src/platform/platform.cpp"
        "src/core/entrypoint.cpp"
)

# List of header files
set(HDR_FILES
        "src/core/defines.h"
        "include/compass.h"
        "src/core/application.h"
        "src/core/entrypoint.h"
        "src/platform/platform.h"
)

# Conditionally include or exclude the file based on the platform
if (WIN32)
    # Include these files on Windows
    list(APPEND SRC_FILES "src/platform/windows-platform.cpp")
    list(APPEND HDR_FILES "src/platform/windows-platform.h")
endif ()

add_library(compass STATIC ${SRC_FILES} ${HDR_FILES})

# Targets linked to compass are not linked to PRIVATE
# Targets linked to compass are vicariously linked to PUBLIC
target_include_directories(compass
        PUBLIC "include"
        PUBLIC "${PROJECT_BINARY_DIR}"
)

target_link_libraries(compass PRIVATE Microsoft.GSL)