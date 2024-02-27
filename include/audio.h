#pragma once

#include "common.h"
#include <alc.h>

namespace ustream {

class Audio {

private:
  ALCcontext *ctx;
  ALCdevice *physical_device;
  const ALCchar *device_name = NULL;

public:
  Audio();
  void Init();
  ~Audio();
};
} // namespace ustream