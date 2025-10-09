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

    CROW_ROUTE(m_app, "/orders/<int>").methods("GET"_method)
        ([this](int orderId){
            std::string downstreamUrl = m_ordersServiceUrl + "/" + std::to_string(orderId);
            cpr::Response r = cpr::Get(cpr::Url{downstreamUrl}, cpr::Header{{"Accept", "application/json"}});
            return crow::response(r.status_code, r.text);
        });

    CROW_ROUTE(m_app, "/orders").methods("GET"_method)
    ([this](const crow::request& req){
        cpr::Parameters params = {};
        if(auto product_id = req.url_params.get("product_id")){
            params.Add({"product_id", product_id});
        }

        if(auto min_amount = req.url_params.get("min_amount")){
            params.Add({"min_amount", min_amount});
        }

        if(auto max_amount = req.url_params.get("max_amount")){
            params.Add({"max_amount", max_amount});
        }

        if(auto status = req.url_params.get("status")){
            params.Add({"status", status});
        }

        cpr::Response r = cpr::Get(
            cpr::Url{m_ordersServiceUrl + "/orders"},
            cpr::Header{{"Accept", "application/json"}},
            params
        );
        return crow::response(r.status_code, r.text);
    });
}