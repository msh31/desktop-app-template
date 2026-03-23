#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM //use glad not their own loader

#ifdef __cplusplus
#include <iostream>
#include <string>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>
