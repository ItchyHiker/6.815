#
# Modify HALIDE_DIR to the appropriate path on your machine.
#
# Special instructions for Mac users
# ==================================
# You need to or must have installed libpng through Macports or Homebrew.
# Assuming that the installation succeeded, you should be able to run
#
# The brew command for installing libpng is
# brew install libpng
#
# libpng-config --I_opts
# libpng-config --L_opts
#
# Please add the output of the above commands to the following variables:
# PNG_INC
# PNG_LIB

MKDIR	:= mkdir -p
RM		:= rm -f
CP		:= cp -f
CXX		:= g++ -Wall -g3 -ggdb -std=c++11 -I.

# TODO: changeme to your halide path
HALIDE_DIR ?= /Users/vincent/Libs/Halide
HALIDE_LIB := $(HALIDE_DIR)/build/src/libHalide.dylib

INC  := $(wildcard  *.h)
SRC  := $(wildcard  tutorial*.cpp)
APPS := $(notdir $(SRC:.cpp=))

# TODO: (OSX users) add the configuration flags for libpng
PNG_INC := -I/usr/local/Cellar/libpng/1.6.37/include/libpng16
PNG_LIB := -L/usr/local/Cellar/libpng/1.6.37/lib

all: a9 $(APPS)
	mkdir -p Output

CXXFLAGS := $(PNG_INC) -I$(HALIDE_DIR)/include/ -I$(HALIDE_DIR)/tools/ -I. -g -Wall
LDFLAGS  := $(PNG_LIB) -L$(HALIDE_DIR)/build/src/ -lz -lpthread -ldl -lncurses -lpng  -lHalide `libpng-config --cflags --ldflags` -ljpeg

%: %.cpp $(HALIDE_LIB)
	$(CXX) $(CXXFLAGS) $< $(HALIDE_LIB) $(LDFLAGS) -o $@

a9: a9_main.cpp a9.cpp a9.hpp $(HALIDE_LIB)
	$(CXX) $(CXXFLAGS) a9_main.cpp a9.cpp $(HALIDE_LIB) $(LDFLAGS) -o $@

run: a9
	./a9

clean:
	$(RM) $(APPS) Output/* a9
	$(RM) -rf *.dSYM
	rm -rf Output
