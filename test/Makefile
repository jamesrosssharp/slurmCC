SRC_DIR=../src

BUILD_DIR=../build

TARGET=$(BUILD_DIR)/slurmc-tester

all: $(TARGET)

CPP_SRC	= $(wildcard $(SRC_DIR)/*.cpp)
HEADERS	= $(wildcard $(SRC_DIR)/*.h)

CPP_OBJ = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(CPP_SRC)))
CPP_OBJ_NOMAIN = $(filter-out $(BUILD_DIR)/main.o, $(CPP_OBJ))

TEST_DIR=../test

TEST_SRC = $(TEST_DIR)/main.cpp
TEST_SRC_DEP = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(patsubst %.cpp, $(BUILD_DIR)/%.to,$(notdir $(TEST_SRC)))



$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	@echo "CXX $<"
	@g++ -std=c++20 -O3 -c -ggdb -o $@ -I$(SRC_DIR) $<

$(BUILD_DIR)/%.to: $(TEST_DIR)/%.cpp $(HEADERS) $(TEST_SRC_DEP)
	@mkdir -p $(BUILD_DIR)
	@echo "CXX $<"
	@g++ -std=c++20 -c -o $@ -I$(SRC_DIR) -I$(TEST_DIR) $<

clean:
	rm -r build

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(CPP_OBJ_NOMAIN) $(TEST_OBJ)
	@g++ -o $@ $(CPP_OBJ_NOMAIN) $(TEST_OBJ) -lgtest
	@echo "LNK"

.PHONY: test
test: $(TARGET)
	./$(TARGET)


