/*
headers/kconfig.h
AVR MOS kernel configuration header. Should be included in kernel.c only.
*/

//Kernel Configuration Flags. See FLAGS.md for descriptions and usage.

//Global flags (KF_ALL_x)
#define KF_ALL_DEBUG = 0 //Sets debug mode. 

//Initialization flags (KF_INIT_x)
#define KF_INIT_RETRYS = Governs the number of retries from recoverable errors before the kernel panics. Defualts to 3.

//Execution flags (KF_LOOP_x)