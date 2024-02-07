#include <iostream>
#include "./log/log.h"
#include "spdlog/spdlog.h"

int main() {

    Log logger;
    logger.CreateLog();
    
    // 日志输出示例
    SPDLOG_TRACE("This is a trace message");
    SPDLOG_DEBUG("This is a debug message");
    SPDLOG_INFO("This is an info message");
    SPDLOG_WARN("This is a warning message");
    SPDLOG_ERROR("This is an error message");
    SPDLOG_CRITICAL("This is a critical message");

    return 0;
}
