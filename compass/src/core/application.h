#pragma once

namespace Compass {
    class Application {
    public:
        Application() = default;

        Application(const Application &) = delete;
        Application(Application &&) = delete;
        Application &operator=(const Application &) = delete;
        Application &operator=(Application &&) = delete;

        virtual ~Application() = default;

        void Run();

    private:
        bool _isRunning = false;
    };

    // To be defined in client
    extern Application *CreateApplication();
}