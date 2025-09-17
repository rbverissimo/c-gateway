#include "OrdersController.h"
#include <cpr/cpr.h>
#include <iostream>

OrdersController::OrdersController(crow::SimpleApp& app, const std::string& ordersServiceUrl): 
    m_app(app), m_ordersServiceUrl(ordersServiceUrl) {}

void OrdersController::setupRoutes(){
    CROW_ROUTE(m_app, "/orders").methods("POST"_method)
        ([this](const crow::request& req){
            cpr::Response r = cpr::Post(
                cpr::Url{m_ordersServiceUrl},
                cpr::Body{req.body},
                cpr::Header{{"Content-Type", "application/json"}}
            );

            return crow::response(r.status_code, r.text);
        });
}