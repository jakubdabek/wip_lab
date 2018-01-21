CC = clang
CFLAGS = -Wall --pedantic -std=c11

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,obj/%.o,$(SRCS))

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJS): obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) program *~ **/*~

.PHONY: all clean
