CC = clang
CFLAGS = -Wall --pedantic -std=c11
LDFLAGS = -lm

NAMES = north south east west distance newagent main
OBJS = $(addprefix obj/, $(addsuffix .o, $(NAMES)))

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJS): obj/%.o : src/%.c src/agents.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f program $(OBJS) *~ **/*~

.PHONY: all clean
