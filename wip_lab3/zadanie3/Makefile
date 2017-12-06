CC = clang
CFLAGS = -Wall --pedantic -std=c11

NAMES = main phi
OBJS = $(addprefix obj/, $(addsuffix .o, $(NAMES)))

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJS): obj/%.o : src/%.c src/phi.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f program $(OBJS) *~ **/*~

.PHONY: all clean
