# Makefile for libfs of FOOS
C_SOURCES=$(wildcard *.c)
OBJ=$(C_SOURCES:.c=.o)
CFLAGS=-ffreestanding
CPPFLAGS=-I../include
CFLAGS+=$(CPPFLAGS)

.PHONY:	all clean dep clean-dep

all:	libfs.a

%.o:	%.c
	$(CC) -m32 -c -o $@ $< $(CFLAGS)

libfs.a:	$(OBJ)
	$(AR) rc $@ $^

clean:
	$(RM) -rf *.o *.a

install:
	mkdir -p $(DEST)/lib
	install -c libfs.a $(DEST)/lib

dep:
	sed '/\#\#\# Dependencies/q' < Makefile > Makefile_temp
	(for i in *.c;do $(CPP) $(CPPFLAGS) -M $$i;done) >> Makefile_temp
	cp Makefile_temp Makefile
	$(RM) -f Makefile_temp

clean-dep:
	sed '/\#\#\# Dependencies/q' < Makefile > Makefile_temp
	cp Makefile_temp Makefile
	$(RM) -f Makefile_temp
### Dependencies
devfs.o: devfs.c ../include/foos/system.h ../include/inttypes.h \
 ../include/foos/fs.h ../include/foos/devfs.h ../include/foos/device.h \
 ../include/foos/kmalloc.h ../include/errno.h ../include/assert.h \
 ../include/string.h
ramfs.o: ramfs.c ../include/foos/fs.h ../include/inttypes.h \
 ../include/foos/devfs.h ../include/foos/kmalloc.h \
 ../include/foos/device.h ../include/foos/system.h \
 ../include/foos/ramfs.h ../include/dev/ramdisk.h ../include/dev/serial.h \
 ../include/assert.h ../include/stdio.h ../include/stdarg.h \
 ../include/string.h
wrap.o: wrap.c ../include/foos/system.h ../include/inttypes.h \
 ../include/foos/fs.h ../include/foos/device.h ../include/foos/kmalloc.h \
 ../include/errno.h ../include/string.h ../include/assert.h \
 ../include/stdio.h ../include/stdarg.h
