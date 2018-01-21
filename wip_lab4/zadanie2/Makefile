CC = clang
CFLAGS = -Wall --pedantic -std=c11

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,obj/%.o,$(SRCS))

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJS): obj/%.o : src/%.c src/io_utility.h
	$(CC) $(CFLAGS) -c -o $@ $(filter %.c,$^)

test: test/test
	test/test >results.csv
	grep -qv ERROR results.csv
	cat results.csv | cut -d, -f2 | sort | uniq -c | awk '{print $$2, $$1}' >statistics.txt
test/test: obj/test_io_utility.o obj/utility.o obj/main.o src/io_utility.h src/utility.h
	$(CC) $(CFLAGS) -o $@ $(filter %.o,$^)
obj/test_io_utility.o: test/test_io_utility.c src/io_utility.h src/utility.h
	$(CC) $(CFLAGS) -c -o $@ $(filter %.c,$^)

clean:
	rm -f $(OBJS) program obj/test_io_utility.o test/test results.csv *~ **/*~

.PHONY: all test clean
