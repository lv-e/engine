csrc = $(wildcard *.c) \
       $(wildcard sandbox/*.c) \
       $(wildcard src/*.c)

obj = $(csrc:.c=.o)

COMPILER = gcc

game: $(obj)
	$(COMPILER) -o sandbox/$@ $^ -I.

.PHONY:
	clean

clean:
	rm -f $(obj) game