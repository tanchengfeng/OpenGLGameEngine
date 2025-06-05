# engine/Controller/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(Controller STATIC ${RENDERER_SRC} ${RENDERER_HEADERS} "include/Controller/RoleController.h" "src/RoleController.cpp")
target_include_directories(Controller PUBLIC include)
target_link_libraries(Controller PUBLIC engine)