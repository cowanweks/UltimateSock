
OBJS     = $(OBJDIR)/App.o $(OBJDIR)/gui.o $(OBJDIR)/App.res.o
BIN      = $(BINDIR)/App.exe

all: $(BIN)

$(OBJDIR)/%.o: %.c
	$(CC) $(CCFLAGS) $(DEFINES) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES) -o $@ $^

$(OBJDIR)/%.res.o: $(ROOT_DIR)/resources/%.rc
	$(RC) -o $@ $^

$(BIN): $(OBJS)
	$(CXX) $(LDFLAGS) -mwindows -o $@ $^