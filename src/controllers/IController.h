#pragma once

class IController {
    public:
        virtual ~IController() = default;
        virtual void setupRoutes() = 0;
};