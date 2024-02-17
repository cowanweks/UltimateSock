CC=clang
CCFLAGS=-c -g -I include
LDFLAGS=-lWs2_32
BINDIR=bin
OBJDIR=obj
DEFINES=-DNDEBUG

.PHONY: bootstrap clean

all: bootstrap $(BINDIR)/server $(BINDIR)/client $(BINDIR)/App

$(OBJDIR)/%.o:  src/server/%.c
	$(CC) $(CCFLAGS) $(DEFINES) -o $@ $^

$(OBJDIR)/%.o:  src/client/%.c
	$(CC) $(CCFLAGS) $(DEFINES) -o $@ $^

$(BINDIR)/client: $(OBJDIR)/client.o
	$(CC) $(LDFLAGS) -o $@ $^

$(BINDIR)/server: $(OBJDIR)/server.o
	$(CC) $(LDFLAGS) -o $@ $^

$(BINDIR)/App: $(OBJDIR)/App.o $(OBJDIR)/gui.o
	$(CC) $(LDFLAGS) -L lib -lglfw3 -mwindows -o $@ $^

bootstrap:
	mkdir -p obj bin

clean:
	$(RM) -rf obj bin