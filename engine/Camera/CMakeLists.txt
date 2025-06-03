# engine/Camera/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(Camera STATIC ${RENDERER_SRC} ${RENDERER_HEADERS})
target_include_directories(Camera PUBLIC include)
target_link_libraries(Camera PUBLIC engine)


