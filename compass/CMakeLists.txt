# Configure version header
configure_file(
    "${PROJECT_SOURCE_DIR}/version.h.in"
    "${PROJECT_BINARY_DIR}/version.h"
)

# List of source files
set(SRC_FILES
    "src/core/application.cpp"
)

# List of header files
set(HDR_FILES
    "src/core/defines.h"
    "include/compass.h"
    "src/core/application.h"
    "src/core/entry-point.h" 
    "src/platform/platform.h")

add_library(compass STATIC ${SRC_FILES} ${HDR_FILES})

# Targets linked to compass are not linked to PRIVATE
# Targets linked to compass are vicariously linked to PUBLIC
target_include_directories(compass
    PUBLIC "include"
    PUBLIC ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
    
)