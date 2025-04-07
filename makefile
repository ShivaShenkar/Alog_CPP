CXX = clang++
CXXFLAGS = -Wall -Wextra -g

# Source files and target
SRC = main.cpp graph.cpp algos.cpp binaryheap.cpp edge-list.cpp queue.cpp arraylist.cpp unionfind.cpp
TARGET = main

# Test source and target
TEST_SRC = tests.cpp
TEST_TARGET = tests

# Default target
all: $(TARGET)

# Rule to build the main target
$(TARGET): $(SRC)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Rule to build the test target
$(TEST_TARGET): $(TEST_SRC)
    $(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC)

# Run tests
test: $(TEST_TARGET)
    ./$(TEST_TARGET)

# Clean up generated files
clean:
    rm -f $(TARGET) $(TEST_TARGET)
