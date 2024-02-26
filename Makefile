CC=clang++
RC=windres
CCFLAGS= -std=c++11 -c -g -I include -I $(OPENAL_SDK)\include
LDFLAGS= -L lib -lglfw3 -lvlccore -lvlc -L $(OPENAL_SDK)\libs\win64
BINDIR=bin
BIN=$(BINDIR)/App.exe
OBJDIR=$(BINDIR)/obj
DEFINES=-DNDEBUG

.PHONY: bootstrap clean

all: bootstrap $(BIN)

$(OBJDIR)/%.res.o: resources/%.rc
	$(RC) -o $@ $^

$(OBJDIR)/%.o: src/%.c lib/vlc/%.c
	$(CC) $(CCFLAGS) $(DEFINES) -o $@ $^

$(OBJDIR)/%.o: src/%.cpp
	$(CC) $(CCFLAGS) $(DEFINES) -o $@ $^

$(BIN): $(OBJDIR)/audio.o $(OBJDIR)/App.o $(OBJDIR)/gui.o $(OBJDIR)/App.res.o
	$(CC) $(LDFLAGS) -mwindows -o $@ $^

bootstrap:
	@mkdir -p bin/obj

clean:
	@rm -rf bin/obj bin/*.exe
