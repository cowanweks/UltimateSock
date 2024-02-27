export CC       = clang
export CXX      = clang++
export RC       = windres
export CCFLAGS  = -c -g $(INCDIR)
export CXXFLAGS += $(CCFLAGS) -std=c++11
export ASMFLAGS =
export LDFLAGS  = $(LDDIR) -lglfw3 -lvlccore -lvlc -lOpenAL32
export ROOT_DIR = $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export BINDIR   = $(ROOT_DIR)/bin
export DEFINES  = -DNDEBUG
export SUBDIRS  = $(ROOT_DIR)/src/core $(ROOT_DIR)/src/client
export OBJDIR   = $(BINDIR)/obj
export LDDIR    = -L $(ROOT_DIR)/lib -L $(OPENAL_SDK)/libs/win64
export INCDIR   = -I $(ROOT_DIR)/include -I $(OPENAL_SDK)/include
SETUP           = $(ROOT_DIR)/out

.PHONY: bootstrap subdirs $(SUBDIRS) clean

all: bootstrap $(ROOT_DIR)/src/core $(ROOT_DIR)/src/client

$(OBJDIR)/%.res.o: resources/%.rc
	$(RC) -o $@ $^


subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

bootstrap:
	@mkdir -p out bin/obj

package:
	@makensis

clean:
	@rm -rf out $(ROOT_DIR)/bin/obj $(ROOT_DIR)/bin/*.exe $(ROOT_DIR)/bin/core.dll
