
# Compiler user
CC=g++

SOURCE_DIR=utils
BUILD_DIR=bin
TMP_FILE=utils/a.out
SWP_FILES=utils/.*.swp

all: printenv echo wc

printenv:
	$(CC) $(SOURCE_DIR)/printenv.cpp -o $(BUILD_DIR)/printenv

echo: 
	$(CC) $(SOURCE_DIR)/echo.cpp -o $(BUILD_DIR)/echo

wc: 
	$(CC) $(SOURCE_DIR)/wc.cpp -o $(BUILD_DIR)/wc

clean:
	rm -rf $(BUILD_DIR)/*
	rm -rf $(TMP_FILE)
	rm -rf $(SWP_FILES)
