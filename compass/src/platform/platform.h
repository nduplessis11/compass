#pragma once

namespace Compass {
    class IPlatform {
    public:
        IPlatform() = delete;
        IPlatform(const IPlatform &) = delete;
        IPlatform(IPlatform &&) = delete;
        IPlatform &operator=(const IPlatform &) = delete;
        IPlatform &operator=(IPlatform &&) = delete;
        virtual ~IPlatform() = delete;

        virtual void Initialize() = 0;
        virtual void Shutdown() = 0;
        virtual void DisplayMessage(const char *message) const = 0;
    };
}