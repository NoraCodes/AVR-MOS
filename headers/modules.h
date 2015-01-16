/*
headers/modules.h
Use this file to enable and disable modules for your kernel.
*/

/* modules/pinraw/pinraw.c 
PinRaw module. Used for accessing raw digital pins - basically, try not to use this. If you have to use this, you should probably be writing a module.
It is included here as an example, and for prototyping.
*/
#define MOD_PINRAW 0
#define MOD_SERIAL 0
