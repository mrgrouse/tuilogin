CC = clang
.DEFAULT_GOAL := tuilogin

CFLAGS = -O2 -Werror -Wall -Wextra
DEBUG_CFLAGS = -O0 -Werror -Wall -Wextra -g

LDFLAGS = -lform -lncursesw
#LDFLAGS=-fPIE -static # for static linking with [sabotage-linux/netbsd-curses]

SRCS = ./*.c
OBJS = $(SRCS:.c=.o)
BIN=tuilogin

PREFIX=/usr/local

tuilogin: o
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN) $(LDFLAGS)

o:
	$(CC) $(CFLAGS) -c $(SRCS)

debug:
	$(CC) $(DEBUG_CFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS)

clean:
	rm -f $(BIN) $(OBJS)

install: tuilogin
	cp -f tuilogin $(PREFIX)/bin/$(BIN)
	echo "tuilogin installed at $(PREFIX)/bin/$(BIN)"
