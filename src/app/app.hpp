#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class App {
public:
    ~App();

    void init();
    void render();

    GLFWwindow* window = nullptr;
private:
    bool setup_opengl();
    bool setup_imgui();
};
