#include <cstdlib>
#include "crow.h"
#include "controllers/OrdersController.h"
#include "controllers/AuthController.h"
#include "config/Config.h"

int main(){

    crow::SimpleApp app;
    Config config;

    OrdersController ordersController(app, config.getOrdersServiceUrl());
    ordersController.setupRoutes();

    AuthController authController(app, config.getAuthServiceUrl());
    authController.setupRoutes();

    CROW_ROUTE(app, "/health")([](){
        return "API Gateway is healthy";
    });

    app.port(18080).multithreaded().run();
}