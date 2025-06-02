# runtime/CMakeLists.txt

add_executable(runtime_app main.cpp)
target_link_libraries(runtime_app PRIVATE engine)