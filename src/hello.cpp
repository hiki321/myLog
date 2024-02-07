#include <iostream>  
#include <spdlog/spdlog.h>  
  
int main() {  
    // 创建并初始化一个logger    
  
    // 输出不同等级的日志信息  
    spdlog::info("Welcome to spdlog!");
    spdlog::warn("This is a warning message.");
    spdlog::error("This is an error message.");
    spdlog::critical("This is a critical message.");  
    // logger->warn("This is a warning message.");  
    // logger->error("This is an error message.");  
    // logger->critical("This is a critical message.");  
  
    return 0;  
}