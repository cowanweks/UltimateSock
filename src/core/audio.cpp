#include "audio.h"

using namespace ustream;

Audio::Audio() {}

Audio::~Audio() {}

// Initialize the sound device
void Audio::Init() {

  // Enumerate all sound devices
  physical_device = alcOpenDevice(device_name);

  // Create device context if device found
  if (physical_device) {
    ctx = alcCreateContext(physical_device, NULL);
    alcMakeContextCurrent(ctx);
  }
}