# List of source files
set(SRC_FILES
    "src/core/application.cpp"
    #"src/platform/windows_platform.cpp"
 )

# List of header files
set(HDR_FILES
    "src/core/defines.h"
    "include/compass.h"
    "src/core/application.h"
    "src/core/entry-point.h" 
    "src/platform/platform.h")

# Conditionally include or exclude the file based on the platform
if(WIN32)
    # Include these files on Windows
    list(APPEND SRC_FILES "src/platform/windows_platform.cpp")
endif()

add_library(compass STATIC ${SRC_FILES} ${HDR_FILES})

# Targets linked to compass are not linked to PRIVATE
# Targets linked to compass are vicariously linked to PUBLIC
target_include_directories(compass
    PUBLIC "include"
    PUBLIC "${PROJECT_BINARY_DIR}"
)