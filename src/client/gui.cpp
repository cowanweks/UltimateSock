#include "gui.h"

void create_application_window() {

  if (!glfwInit()) {
    MessageBoxA(NULL, "[x] - Error initializing GLFW!", "[x] - Error", MB_OK);
  }

  // Set application window hints
  glfwWindowHint(GLFW_NO_API, GLFW_TRUE);
  glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

  // Create the window
  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
                                        APPLICATION_TITLE, NULL, NULL);

  if (!window) {
    MessageBoxA(NULL, "[x] - Error Creating window!", "[x] - Error", MB_OK);
  }

  // Set the window icon
  SetClassLongPtrA(
      glfwGetWin32Window(window), GCLP_HICONSM,
      (LONG_PTR)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(48)));

  // Set the Taskbar Icon
  SetClassLongPtrA(
      glfwGetWin32Window(window), GCLP_HICON,
      (LONG_PTR)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(64)));

  while (!glfwWindowShouldClose(window)) {

    glfwSwapBuffers(window);
    application_main_loop();
    glfwPollEvents();
  }
}

// Applications Mainloop
void application_main_loop() {}