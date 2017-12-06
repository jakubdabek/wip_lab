CC = clang
CFLAGS = -Wall --pedantic -std=c11

NAMES = palindrome main
OBJS = $(addprefix obj/, $(addsuffix .o, $(NAMES)))

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJS): obj/%.o : src/%.c src/palindrome.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) program *~ **/*~

.PHONY: all clean
