#AVR - M(odular)O(perating)S(ystem)


The AVR MOS is an operating system for Atmel AVR microcontrollers specifically designed to function with compileable modules that update on each execution loop.

It is originally intended to run on Arduino boards, specifically the Mega 2560 - but it will eventually be set up such that it can be compiled for any AVR uC. In the same vein, it is designed with the ability to switch bootloaders - Arduino, custom (USB, SD, or even network), or none. 

It's architected in such a way that it does not dynamically load modules, but rather it is compiled seperately for each individual project. This preserves storage space and RAM. Modules are selected by defining various compiler preprocessor `#define` directives in the main program and including the file `al_kernel.h`

Each module has a `char <modulename>-init()` function and an `char <modulename>-loop()` function

##Useage (end users)

Users then define the functions `char userInit(void)`, `char userLoop(void)`, and, 'void userPanic(void)`. 

`userInit` is called after the kernel and all modules initialize themselves. It sets up anything the user needs, like 


##Useage (module authors)


##Kernel Flags
Kernel flags are `#define`s that change some aspect of the kernel. They take the form of `KF_<stage>_<name>`. The principal one that most users should be concerned with is KF_ALL_DEBUG.

###Debug Mode
KF_ALL_DEBUG enables  


##Standard Return Codes
 Init and loop functions use the same return codes. One `char` long.

+ 0: Executed successfully.
+ 01: Init failed - internal error, recoverable. Retry. *
+ 02: Loop failed - internal error, recoverable. Retry. *
+ 03: Init failed - out of memory!
+ 04: Loop failed - out of memory!
+ 05: Init failed - reserved.
+ 06: Init failed - reserved.
+ 07: Init failed - reserved.
+ 08: Init failed - reserved.
+ 09: Init failed - reserved.
+ 10: Loop failed - reserved.
+ 11: Loop failed - reserved.
+ 12: Loop failed - reserved.
+ 13: Loop failed - reserved.
+ 14: Loop failed - reserved.
+ 15: Kernel failed - cannot panic.

\*NOTE: Retry only as many times as KF_INIT_RETRYS (default 3). Then panic.