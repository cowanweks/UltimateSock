#pragma once

#include "common.h"

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

void create_application_window();
void application_main_loop();