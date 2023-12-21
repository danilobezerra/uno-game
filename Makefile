CC = g++
CFLAGS = -std=c++17 -I./inc -g

TARGET = uno
SRC_DIR = src
OBJ_DIR = out

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

debug: $(TARGET)
	gdb ./$(TARGET)

clean:
	rm -rf $(TARGET) $(OBJ_DIR)
