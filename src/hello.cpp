#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <ctime>

void createLog() {
     // 获取当前时间
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);
    
    // 格式化当前时间为文件名
    char filename[100];
    std::strftime(filename, sizeof(filename), "example_%Y-%m-%d_%H-%M-%S.log", now_tm);
    
    // 创建控制台输出目标
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    
    // 创建文件输出目标，以当前时间命名文件
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename, true);

    // 创建多路输出目标，包括控制台和文件
    spdlog::logger logger("multi_sink", {console_sink, file_sink});
    
    // 设置日志记录器的日志级别
    logger.set_level(spdlog::level::trace);

    // 将多路输出目标设置为默认的日志记录器
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));
}

int main() {

    createLog();
    
    // 日志输出示例
    SPDLOG_TRACE("This is a trace message");
    SPDLOG_DEBUG("This is a debug message");
    SPDLOG_INFO("This is an info message");
    SPDLOG_WARN("This is a warning message");
    SPDLOG_ERROR("This is an error message");
    SPDLOG_CRITICAL("This is a critical message");

    return 0;
}
