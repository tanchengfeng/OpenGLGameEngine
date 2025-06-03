# engine/Graphics/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(Graphics STATIC ${RENDERER_SRC} ${RENDERER_HEADERS} "include/Graphics/Mesh.h" "src/Mesh.cpp")
target_include_directories(Graphics PUBLIC include)
target_link_libraries(Graphics PUBLIC engine)
