#Makefile for AVR-MOS
project:
	avr-gcc main.c -o PROJECT.o
	
kernel:
	avr-gcc kernel.c -o KERNEL.o
