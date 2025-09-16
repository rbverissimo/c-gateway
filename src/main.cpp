#include "crow.h"
#include <cpr/cpr.h>

int main(){

    crow::SimpleApp app;

    const char* order_service_env = std::getenv("ORDER_SERVICE_PATH");
    const std::string ORDER_SERVICE_PATH = order_service_env ? order_service_env : "";

    CROW_ROUTE(app, "/health")([](){
        return "API Gateway is healthy";
    });

    CROW_ROUTE(app, "/orders").methods("POST"_method)([&ORDER_SERVICE_PATH](const crow::request& req){
        cpr::Response r  = cpr::Post(cpr::Url{ORDER_SERVICE_PATH+"/orders"}, 
            cpr::Body(req.body), 
            cpr::Header{{"Content-Type", "application/json"}}
        );

        crow::response res(r.status_code, r.text);
        res.add_header("Content-Type", "application/json");
        return res;
    });


    app.port(18080).multithreaded().run();
}