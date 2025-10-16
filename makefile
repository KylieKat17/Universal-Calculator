# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
SRC_DIR = src
OBJ_DIR = build
BIN = converter

# Source files (excluding driver.cpp from wildcard ordering to put it last)
MODULES = \
  binaryCalculator \
  binaryConversion \
  bitShift \
  bitWiseOperations \
  hexCalculator \
  hexConversion \
  util

SOURCES = $(addprefix $(SRC_DIR)/,$(addsuffix .cpp,$(MODULES))) $(SRC_DIR)/driver.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Default target
all: $(BIN)

# Link all object files into the final binary
$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp source files into .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Optional run target
run: all
	./$(BIN)

.PHONY: all clean run

