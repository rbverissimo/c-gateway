#include "Config.h"
#include <cstdlib>
#include <iostream>

Config::Config() {
    const char* orders_service_env = std::getenv("ORDERS_SERVICE_PATH");
    if(!orders_service_env){
        std::cerr << "FATAL: ORDERS_SERVICE_PATH not found in environment variables" << std::endl;
    }

    m_ordersServiceurl = orders_service_env;
    std::cout << "Configuration loaded sucessfully";
}

const std::string& Config::getOrdersServiceUrl() const {
    return m_ordersServiceurl;
}