#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app/app.hpp"

#ifdef _WIN32 //forces Windows to treat the app as a GUI Application
#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#endif

int main() {
    App app;
    app.init();

    do{
        app.render();
    }
    while(
glfwGetKey(app.window, GLFW_KEY_Q) != GLFW_PRESS &&
glfwWindowShouldClose(app.window) == 0
);

    return 0;
}
