#include "gui.h"

void create_application_window() {

  if (!glfwInit()) {
    fprintf(stderr, "[x] - Error initializing window!");
  }

  GLFWwindow *window = glfwCreateWindow(400, 500, "", NULL, NULL);

  while (!glfwWindowShouldClose(window)) {

    glfwSwapBuffers(window);

    glfwPollEvents();
  }
}
