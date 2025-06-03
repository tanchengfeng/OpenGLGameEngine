cmake_minimum_required(VERSION 3.15)
project(OpenGLGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ✅ 使用 vcpkg 的包（必须通过命令行传入 toolchain 文件）
# cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Debug

# ✅ 找 OpenGL 相关库
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# ✅ 传入给所有子项目
add_subdirectory(engine)


