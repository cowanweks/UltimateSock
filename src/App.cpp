#include "App.h"

libvlc_instance_t *vlcinst;

int main(int argc, char **argv) {

  atexit(cleanup);

  vlcinst = libvlc_new(0, NULL);

  create_application_window();

  return 0;
}

void cleanup() {}