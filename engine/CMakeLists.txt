# engine/CMakeLists.txt

# 添加所有模块子目录
add_subdirectory(Camera)
add_subdirectory(Renderer)
add_subdirectory(Graphics)
add_subdirectory(Scene)
add_subdirectory(GameObject)
add_subdirectory(Input)
add_subdirectory(WindowGL)
add_subdirectory(Physics)
add_subdirectory(EngineAPI)
add_subdirectory(Core)
add_subdirectory(Controller)

# 将各模块链接成 engine 库（可选）
add_library(engine INTERFACE)
target_link_libraries(engine
    INTERFACE
        Camera
        Renderer
        Graphics
        Scene
        GameObject
        Input
        WindowGL
        Physics
        EngineAPI
        Core
        Controller
)

# 链接到目标图形库
target_link_libraries(engine INTERFACE
    OpenGL::GL
    glfw
    glad::glad
    glm::glm
)


