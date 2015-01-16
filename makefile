#Makefile for AVR-MOS
all:
	avr-gcc main.c -o PROJECT.out

project:
	avr-gcc main.c -o PROJECT.out
	
kernel:
	avr-gcc kernel.c -o KERNEL.out
	
clean:
	rm -rf *.o *.out
