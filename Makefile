CC=clang
CCFLAGS=-c -g -I include
LDFLAGS=-lWs2_32
BINDIR=bin
OBJDIR=obj
DEFINES=-DNDEBUG

all: bootstrap $(BINDIR)/server $(BINDIR)/client

$(OBJDIR)/%.o: src/%.c
	$(CC) $(CCFLAGS) $(DEFINES) -o $@ $<

$(BINDIR)/client: $(OBJDIR)/client.o
	$(CC) $(LDFLAGS) -o $@ $^

$(BINDIR)/server: $(OBJDIR)/server.o
	$(CC) $(LDFLAGS) -o $@ $^

bootstrap:
	mkdir -p obj bin

clean:
	$(RM) -rf obj/* bin/*