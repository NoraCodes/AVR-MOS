#Makefile for AVR-MOS
project:
	avr-gcc main.c -o PROJECT.out
	
kernel:
	avr-gcc kernel.c -o KERNEL.out
	
clean:
	rm -rf *.o *.out
