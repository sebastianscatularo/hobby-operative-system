CC = c++
AS = as
LD = ld
CFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
CFLAGS2 = -ffreestanding -nostdlib -fno-builtin -fno-rtti -fno-exceptions


video.o: video.cpp
	$(CC) -c video.cpp -o video.o $(CFLAGS)

#utils.o: Utils.h
#	$(CC) -c Utils.h -o utils.o $(CFLAGS2)

kernel.o: kernel.cpp
	$(CC) -c kernel.cpp -o kernel.o $(CFLAGS2)

boot.o: boot.s
	$(AS) boot.s -o boot.o

build: kernel.o boot.o video.o #utils.o
	$(LD) -T linker.ld -o kernel.bin boot.o kernel.o video.o # utils.o

run: clean build
	qemu-system-i386 -kernel kernel.bin

clean:
	rm -f *.o
	rm -f *.bin	
