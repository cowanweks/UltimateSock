OBJS     = $(OBJDIR)/audio.o $(OBJDIR)/streamer.o
BIN      = $(BINDIR)/core.dll
LDFLAGS  += -fPIC -shared

all: $(BIN)

$(OBJDIR)/%.o: %.c
	$(CC) $(CCFLAGS) $(DEFINES) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES) -o $@ $^

$(OBJDIR)/%.res.o: resources/%.rc
	$(RC) -o $@ $^

$(BIN): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^