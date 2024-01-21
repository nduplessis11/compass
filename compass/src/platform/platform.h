#pragma once

namespace Compass {
    class IPlatform {
    public:
        IPlatform() = default;
        IPlatform(const IPlatform &) = delete;
        IPlatform(IPlatform &&) = delete;
        IPlatform &operator=(const IPlatform &) = delete;
         IPlatform &operator=(IPlatform &&) = delete;
        virtual ~IPlatform() = 0;

        virtual void Initialize() = 0;
        virtual void Shutdown() = 0;
        virtual void PollEvents() const = 0;
    };
}