CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall
SRC_DIR = src
BIN_DIR = bin

# Source files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/maxPlanarSubset.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = $(BIN_DIR)/mps

# Default target
all: $(TARGET)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET)

# Clean up
clean:
	rm -f $(OBJS)
	rm -rf $(BIN_DIR)

.PHONY: all clean