CC = clang
CFLAGS = -Wall --pedantic --std=c11

NAMES = main solution
OBJS = $(addprefix obj/, main.o solution.o)

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -lm -o $@ $^
$(OBJS): obj/%.o : src/%.c src/solution.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f program $(OBJS) *~ **/*~

.PHONY: all clean
