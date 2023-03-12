cmake_minimum_required(VERSION 3.26.0)
# TODO:写入你的程序名
project("NULL")
# 设置Release (msvc 默认Debug)
# cmake --build . --config Release  (Debug)
# TODO:设置安装路径根目录
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
# TODO:设置安装位置 默认安装Debug
set(INSTALL_PROGRAM bin)


# 头文件
include_directories(${PROJECT_SOURCE_DIR})
# 源文件 SRC_LIST
aux_source_directory(. SRC_LIST)
# file(GLOB_RECURSE SRC_LIST *.cpp *.cc)

# link
# link_directories()
# link_libraries()

# 编译选项
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:utf-8>")

# c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# make sure __cplusplus is defined when using msvc and enable parallel build
if(MSVC)
    string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus /MP")
endif()

set(CMAKE_CXX_EXTENSIONS OFF)


# 可执行文件
add_executable(${PROJECT_NAME} ${SRC_LIST})
# add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

# TODO:安装配置
install(FILES ${PROJECT_BINARY_DIR}/Debug/${PROJECT_NAME}.exe ${PROJECT_BINARY_DIR}/Debug/${PROJECT_NAME}.pdb DESTINATION ${INSTALL_PROGRAM})