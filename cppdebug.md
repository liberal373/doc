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