
# Compiler user
CC=g++

SOURCE_DIR=utils

BUILD_DIR=bin

all: printenv echo

printenv:
	$(CC) $(SOURCE_DIR)/printenv.cpp -o $(BUILD_DIR)/printenv

echo: 
	$(CC) $(SOURCE_DIR)/echo.cpp -o $(BUILD_DIR)/echo

clean:
	rm -rf $(BUILD_DIR)/*
