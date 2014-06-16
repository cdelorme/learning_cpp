
# set compilation flags
CC:=g++
CFLAGS:=-g -Wall
INC:=-I include

# where is the source
SRCDIR:=src

# where should we make our mess?
BUILDDIR:=build

# what is our final application?
TARGET:=bin/cdelorme-ge

# dynamically build source files
SOURCES:=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS:=$(addprefix $(BUILDDIR)/,$(notdir $(SOURCES:.cpp=.o)))

##
#  operations
##

# dynamic build file by name
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

# build all files to target
all: $(OBJECTS)
	$(CC) $^ -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)

# test:
# 	@echo " Testing...";
# 	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# alias targets to avoid file name conflicts (eg make clean != make clean.cpp)
.PHONY: clean test

# default make target is "all"
.DEFAULT: all
