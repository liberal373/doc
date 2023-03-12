## spdlog简单封装
1. 将整个spdlog目录拷入工程,包含spdlog/spdlog.hpp
   - 注意:spdlog中文件inlcude都是spdlog/包含,即应配置spdlog的上级目录为头文件搜索路径
2. 实例化全局静态日志对象 InitSpdlog
4. 使用SPDLOG_TRACE SPDLOG_DEBUG SPDLOG_INFO SPDLOG_WARN SPDLOG_ERROR 等输出
5. 默认向终端输出warn级别及以上,向文件输出所有级别日志
6. 设置日志级别为warn及以上及时输出
7. eg:
    ```
    #include "spdlog/spdlog.hpp"

    static InitSpdlog initSpdlog;
    int main() 
    {
        SPDLOG_DEBUG("THIS IS A DEBUG");

        SPDLOG_ERROR("THIS IS A ERROR!");
        SPDLOG_TRACE("THIS IS A TRACE");
        //...

        return 0;
    }
    ```