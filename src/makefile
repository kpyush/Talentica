CC=gcc
CFLAGS=-I.
DEPS = bl_host_conf.h proto.h transport.h
OBJ = bl_host_app.o proto.o transport_hal.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bl_host: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean run

clean:
	rm -f bl_host bl_host_app.o proto.o transport_hal.o

run:
	./bl_host
