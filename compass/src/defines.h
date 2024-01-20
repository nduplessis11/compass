#pragma once

#ifdef _WIN32
constexpr bool CMPS_PLATFORM_WINDOWS = true;
#elif __linux__
constexpr bool CMPS_PLATFORM_LINUX = true;
#elif __APPLE__
constexpr bool CMPS_PLATFORM_APPLE = true;
#else
constexpr bool CMPS_PLATFORM_UNKNOWN = true;
#endif
