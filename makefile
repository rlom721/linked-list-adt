# Made for specific directory organization
# compiler
CC := g++

# directory names!
SRCDIR := src
BUILDDIR := build
TESTDIR := test

# executable names
TARGET := bin/main  
TESTTARGET := bin/tester

# SRCEXT := cpp         # src file extension ! DOESN'T WORK !
SOURCES := $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))   # patsubst pattern, replacement, text

TESTSRCS := $(filter-out $(SRCDIR)/main.cpp, $(SOURCES)) $(shell find $(TESTDIR) -type f -name *.cpp)
TESTOBJS := $(patsubst $(TESTSRCS)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o)) #$(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))
# TESTOBJS := $(TESTSRCS:.cpp=.o) #$(filter-out $(BUILDDIR)/main.o, $(OBJECTS)) 

CFLAGS := -g -Wall
INC := -I include       # ensure all headers in include folder are accessible

all: $(TARGET)
	@echo " Creating target..."

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

# create executable from test code
tester: 
# $(CC) $(CFLAGS) test/tester.cpp $(INC) -o bin/tester
	@echo " Creating test target..."
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "TESTSRCS: $(TESTSRCS)"
	@echo "TESTOBJS: $(TESTOBJS)"
	#$(CC) $(CFLAGS) $(INC) -c -o build/tester.o test/tester.cpp
	#$(CC) $(TESTOBJS) build/tester.o -o $(TESTTARGET)

# create executable from test code
# tester: $(TESTTARGET)
#	@echo " Creating test target..."

#$(TESTTARGET): $(TESTOBJS)
#	@echo " Linking..."
#	@echo " $(CC) $^ -o $(TESTTARGET)"; $(CC) $^ -o $(TESTTARGET)

run:
	@echo " Running executable main..."
	bin/./main

runtest:
	@echo " Running test..."
	bin/./tester

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(TESTTARGET)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TESTTARGET)

.PHONY: clean
