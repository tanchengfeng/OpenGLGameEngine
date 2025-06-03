# engine/WindowGL/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(WindowGL STATIC ${RENDERER_SRC} ${RENDERER_HEADERS})
target_include_directories(WindowGL PUBLIC include)
target_link_libraries(WindowGL PUBLIC engine)