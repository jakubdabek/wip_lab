CC = clang
CFLAGS = -Wall --pedantic -std=c11

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,obj/%.o,$(SRCS))

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJS): obj/%.o : src/%.c src/match.h
	$(CC) $(CFLAGS) -c -o $@ $<

test: test/test
	test/test < test/tests.csv 2>/dev/null
test_debug: test/test
	test/test < test/tests.csv
test/test: obj/match_test.o obj/match.o src/match.h
	$(CC) $(CFLAGS) -o $@ $< obj/match.o  
obj/match_test.o: test/match_test.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS) program obj/match_test.o test/test *~ **/*~

.PHONY: all test clean
