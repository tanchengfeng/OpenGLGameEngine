# engine/Physics/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(Physics STATIC ${RENDERER_SRC} ${RENDERER_HEADERS})
target_include_directories(Physics PUBLIC include)
target_link_libraries(Physics PUBLIC engine)