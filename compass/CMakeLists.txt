# Configure version header
configure_file(
    "${PROJECT_SOURCE_DIR}/version.h.in"
    "${PROJECT_BINARY_DIR}/version.h"
)

# List of source files
set(SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/compass.cpp"
)

# List of header files
set(HDR_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/defines.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/compass.h"
)

add_library(compass STATIC ${SRC_FILES} ${HDR_FILES})

# Targets linked to compass are not linked to PRIVATE
# Targets linked to compass are vicariously linked to PUBLIC
target_include_directories(compass
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PUBLIC ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
    
)