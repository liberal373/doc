# cpp debug file

## cmake构建

### cmake指定Release、Debug版本

1. msvc平台
```
cmake --build . --config Release //指定生成Release版本
cmake --build . --config Debug //指定生成Debug版本
```
2. MinGW Makefiles(GNU)
```
SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_BUILD_TYPE "Debug")
```

## 动态库使用
### 未找到指定的模块
1. 该库所依赖的东西找不到
   - 比如:alg.dll库依赖Qt5Core.dll,但是程序找不到Qt5Core.dll就会报该错误
   - 使用dumpbin [参数] 库 ; 进行查看库的依赖项

## 字符集

### 指定源码字符集和执行字符集
```
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:gbk>")
```

## 编译出错

### 使用C++17编译时出错：error C2872: 'byte': ambiguous symbol
1. 因为Windows旧的SDK定义有一个byte的类型，但在C++17里也有定义std::byte类型，这样就重复定义了。因此，需要改为只使用一个的方式，这样旧代码能编译通过，也可以写新的代码符合C++17。因而需要一个预定义一个宏：
>     _HAS_STD_BYTE=0

2. 第二种方法就是不要使用“using namesapace std”，对于std里面包含的string、vector等，在使用时前面加std，如“std::string”、“std::vectora”。


### VS编译错误：winsock.h winsock2.h ws2def.h 重定义
1.查找winsock.h winsock2.h windows.h调用的地方
2.确保windows.h包含的地方同时包含winsock2.h(先包含winsock2.h)
如：
```
#include <WinSock2.h>
#include <windows.h>
```
3. 将包含winsock.h的地方修改为包含winsock2.h

## 程序运行

### C\C++控制台程序隐藏方法总结
1. 预处理(在编译器下运行时仍会出现黑框，但直接运行编译好的exe程序就不会显示黑框了)
```
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址
```