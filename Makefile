CC := g++
CFLAGS := -Wall -pedantic --std=c++17 -g

# Variables
	PART1_EXE_NAME := lab6-main.bin
	PART1_EXE_PATH := ./$(PART1_EXE_NAME)

# My Targets

lab6-main.bin:
	@echo Building $@
	$(CC) $(CFLAGS) main.cpp -o $@ \
		&& chmod +x $@

lab6-main:	lab6-main.bin
	$(PART1_EXE_PATH)

debug-lab6-main:	lab6-main.bin
	@echo Building $@
	gdb -x lab6-main-debug-commands.txt lab6-main.bin
