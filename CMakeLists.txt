cmake_minimum_required(VERSION 3.16)

project(HelloWorld LANGUAGES CXX)

add_executable(hello src/hello.cpp src/log/log.cpp)

set(CMAKE_BUILD_TYPE Debug)

# 指定需要链接的库文件  
target_link_libraries(hello spdlog pthread)