#ifndef SPDLOG_HPP
#define SPDLOG_HPP

#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE // 添加宏定义
#include "spdlog.h"
#include "sinks/stdout_color_sinks.h"
#include "sinks/basic_file_sink.h"
class InitSpdlog
{
public:
    InitSpdlog()
    {
        Init();
    }
    ~InitSpdlog()
    {
        Destroy();
    }
private:
    void Init() 
    {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::warn);

        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("plogs/pulin.log", true);
        file_sink->set_level(spdlog::level::trace);

        std::shared_ptr<spdlog::logger> logger(new spdlog::logger("multi_sink", {console_sink, file_sink}));
        logger->set_level(spdlog::level::trace);
        spdlog::set_default_logger(logger);

        // https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
        spdlog::set_pattern("[%H:%M:%S][%L][%s:%#] %v");
        // 设置及时打印(警告级别及以上)
        spdlog::flush_on(spdlog::level::warn);
        SPDLOG_INFO("spdlog init sucessful!!!");
    }
    void Destroy(){
        spdlog::shutdown();
    }
};

#endif // SPDLOG_HPP