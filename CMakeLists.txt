cmake_minimum_required(VERSION 3.22)

project(json-standard)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json 3.10.5 REQUIRED)

add_executable(json-standard main.cpp)
