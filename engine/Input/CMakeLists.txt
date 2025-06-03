# engine/Input/CMakeLists.txt

file(GLOB_RECURSE RENDERER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS include/**/*.h)

add_library(Input STATIC ${RENDERER_SRC} ${RENDERER_HEADERS} "include/InputState.h" "include/KeyCodes.h" "include/MouseCodes.h" "include/Mapping/InputBinding.h" "include/Mapping/InputActionMap.h" "include/Mapping/InputAxisMap.h")
target_include_directories(Input PUBLIC include)
target_link_libraries(Input PUBLIC engine)
