#pragma "once"
#include "crow.h"
#include "IController.h"
#include <string>

class AuthController: public IController {
    public:
        AuthController(crow::SimpleApp& app, const std::string& authServiceUrl);

        void setupRoutes() override;
    private:
        crow::SimpleApp& m_app;
        std::string m_authServiceUrl;
};