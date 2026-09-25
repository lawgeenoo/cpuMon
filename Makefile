CC=gcc
CFLAGS=-Iinclude -Wall -Wextra -Werror -Wpedantic -g

SRC=\
src/main.c \
src/system/cpu.c \
src/system/temp.c \
src/alert/alert.c \
src/ui/dashboard.c \
src/ui/graph.c \
src/core/history.c

OUT=cpu-monitor

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

clean:
	rm -f cpu-monitor

