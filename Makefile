
# Compiler user
CC=g++

SOURCE_DIR=utils

BUILD_DIR=bin

all: printenv

printenv:
	$(CC) $(SOURCE_DIR)/printenv.cpp -o $(BUILD_DIR)/printenv

clean:
	rm -rf $(BUILD_DIR)/*
