CXX := g++
CXXFLAGS := -std=c++14
LIBS := -L/opt/homebrew/lib -lxxhash
INCLUDES := -I~/Desktop/DM
SRCS := SpaceSaving.cpp main.cpp
TARGET := main

.PHONY: all clean

all: clean $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)
