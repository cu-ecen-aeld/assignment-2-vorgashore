CC = gcc
CFLAGS = -Wall

ifdef CROSS_COMPILE
	ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
		CC = aarch64-none-linux-gnu-gcc
	endif
endif

program_name = writer

all: $(program_name)

$(program_name): writer.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(program_name)
	rm -f *.o
