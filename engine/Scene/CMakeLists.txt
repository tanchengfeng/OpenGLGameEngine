# engine/Scene/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(Scene STATIC ${RENDERER_SRC} ${RENDERER_HEADERS})
target_include_directories(Scene PUBLIC include)
target_link_libraries(Scene PUBLIC engine)