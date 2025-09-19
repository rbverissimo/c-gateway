#pragma once
#include <string>

class Config {
    public:
        Config();
        const std::string& getOrdersServiceUrl() const;
    private:
        std::string m_ordersServiceurl;
};