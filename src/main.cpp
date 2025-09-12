#include "crow.h"

int main(){

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Available endpoints: \n  1 . /health \n 2. /testing  ";
    });

    CROW_ROUTE(app, "/health")([](){
        return "API Gateway is healthy";
    });

    CROW_ROUTE(app, "/testing")([](){
        return "This is just for testing!";
    });

    app.port(18080).multithreaded().run();
}