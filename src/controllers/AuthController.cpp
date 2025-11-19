#include "AuthController.h"
#include <cpr/cpr.h>
#include <iostream>

AuthController::AuthController(crow::SimpleApp& app, const std::string& authServiceUrl):
    m_app(app), m_authServiceUrl(authServiceUrl) {}

void AuthController::setupRoutes(){

    CROW_ROUTE(m_app, "/v1/auth/health").methods("GET"_method)
        ([this](const crow::request& req){
            std::string downstreamUrl = m_authServiceUrl + "/health";
            cpr::Response r = cpr::Get(cpr::Url(downstreamUrl), cpr::Header{{"Accept", "application/json"}});
            return crow::response(r.status_code, r.text);
    });

}