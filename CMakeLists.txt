cmake_minimum_required(VERSION 3.10)
project(c-gateway CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(api-gateway-cpp 
    src/main.cpp 
    src/controllers/OrdersController.cpp
    src/controllers/AuthController.cpp
    src/config/Config.cpp
    )

find_package(Crow REQUIRED)
find_package(cpr REQUIRED)
target_link_libraries(api-gateway-cpp PRIVATE Crow::Crow cpr::cpr)


