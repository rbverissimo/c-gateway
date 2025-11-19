#pragma once
#include <string>

class Config {
    public:
        Config();
        const std::string& getOrdersServiceUrl() const;
        const std::string& getAuthServiceUrl() const;
    private:
        std::string m_ordersServiceurl;
        std::string m_authServiceurl;
};