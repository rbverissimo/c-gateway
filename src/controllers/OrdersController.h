#pragma once
#include "crow.h"
#include "IController.h"
#include <string>

class OrdersController: public IController {
    public:
        OrdersController(crow::SimpleApp& app, const std::string& ordersServiceUrl);

        void setupRoutes() override;
    private:
        crow::SimpleApp& m_app;
        std::string m_ordersServiceUrl;
};