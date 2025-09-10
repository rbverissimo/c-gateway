#include "crow.h"

int main(){

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Available endpoints: \n  1 . /health ";
    });

    CROW_ROUTE(app, "/health")([](){
        return "API Gateway is healthy";
    });

    app.port(18080).multithreaded().run();
}