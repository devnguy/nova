SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -Wall
# CPPFLAGS := ...
CXXFLAGS := -std=c++11
TARGET := nova

$(TARGET): $(OBJ_FILES)
	@echo [LINKING]  All files . . .
	g++ $(LDFLAGS) -o $@ $^
	@echo [SUCCESS]  File Name: $(TARGET)
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo [BUILDING] $< . . .
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(TARGET)