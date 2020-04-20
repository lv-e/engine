csrc = $(wildcard *.c) \
       $(wildcard sandbox/*.c) \
	   $(wildcard lv-engine/*.c) \
       $(wildcard lv-engine/**/*.c)

obj 		= $(csrc:.c=.o)
flags 		= -DLV_USE_STDIO=1
includes 	= -I./

CFLAGS 	 	= $(flags) $(includes)
CC 			= gcc
LINKER 		= g++

game: $(obj)
	$(LINKER) -o sandbox/$@ $^ -I.

.PHONY:
	clean

clean:
	rm -f $(obj) game