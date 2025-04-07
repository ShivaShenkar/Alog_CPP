CXX = clang++
CXXFLAGS = -Wall -Wextra -g

# Source files and target
SRC = main.cpp graph.cpp algos.cpp binaryheap.cpp edge-list.cpp queue.cpp arraylist.cpp unionfind.cpp
TARGET = main

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up generated files
clean:
	rm -f $(TARGET)