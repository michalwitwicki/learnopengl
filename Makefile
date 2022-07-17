CC = gcc
CFLAGS = -std=c11 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing 
CFLAGS += -Wno-pointer-arith -Wno-unused-parameter

BIN_DIR = bin
OUT_NAME = out.exe

# --- DEPENDENCIES AND LIBS FILES ---
CFLAGS += 	-I deps/GLFW/include \
			-I deps/GLAD/include/KHR \
			-I deps/GLAD/include \
			-I deps/linmath/include

LDFLAGS += 	-L deps/GLFW \
			-lglfw3 \
			-lgdi32 \
			-lopengl32

SRC = deps/GLAD/src/gl.c

# --- PROJECT FILES ---
SRC += 	src/main.c \
		src/game.c \
		src/renderer.c \
		src/window.c

OBJ := $(SRC:%.c=$(BIN_DIR)/%.o)

.PHONY: all clean build run

# --- BUILDING ---
build: $(OBJ)
	$(CC) -o $(BIN_DIR)/$(OUT_NAME) $^ $(LDFLAGS)

$(BIN_DIR)/%.o: %.c
	@mkdir -p '$(@D)'
	$(CC) -o $@ -c $< $(CFLAGS)

# --- UTILS ---
all: build run
call: clean build run

clean:
	rm -rf ./$(BIN_DIR)

run:
	./$(BIN_DIR)/$(OUT_NAME)