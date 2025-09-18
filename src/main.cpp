#include <cstdlib>
#include "crow.h"
#include "controllers/OrdersController.h"

int main(){

    crow::SimpleApp app;

    const char* orders_service_path_ptr = std::getenv("ORDERS_SERVICE_PATH");
    const std::string ORDERS_SERVICE_PATH = orders_service_path_ptr ? orders_service_path_ptr : "";

    OrdersController ordersController(app, ORDERS_SERVICE_PATH);
    ordersController.setupRoutes();

    CROW_ROUTE(app, "/health")([](){
        return "API Gateway is healthy";
    });

    app.port(18080).multithreaded().run();
}