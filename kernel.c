/*
kernel.c
AVR MOS Kernel main file - ONLY THIS should be included in the Arduino sketch by most users.
Note: this is an Arduino sketch!*/

#include "headers/kconfig.h" //Include kernel headers. These allow configuration of the kernel.

//prototype user callback functions.
char userInit(void);
char userLoop(void);
void userPanic(void);

void setup(){

}

void loop(){

}