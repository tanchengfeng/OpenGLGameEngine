# engine/Character/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(Character STATIC ${RENDERER_SRC} ${RENDERER_HEADERS})
target_include_directories(Character PUBLIC include)
target_link_libraries(Character PUBLIC engine)