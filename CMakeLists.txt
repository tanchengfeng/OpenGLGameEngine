cmake_minimum_required(VERSION 3.15)
project(OpenGLGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 如果使用 vcpkg，需要手动传入 toolchain 文件
# 例如：cmake -DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/scripts/buildsystems/vcpkg.cmake

# 引入子模块
add_subdirectory(engine)
add_subdirectory(runtime)
# add_subdirectory(tests) 可选

