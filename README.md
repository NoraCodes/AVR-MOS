#AVR M(odular)O(perating)S(ystem)


The AVR MOS is an operating system for Atmel AVR microcontrollers designed to function with compileable modules that update on each execution loop, or can register for interrupts. It is uses buffers to which the user writes to control each module; the kernel then executes the various actions required by those modules with the data and parameters from the buffers.

It is originally intended to run on Arduino boards, specifically the Mega 2560 - but it might eventually be set up such that it can be run on any AVR uC. In the same vein, it is designed with the ability to interoperate with bootloaders - Arduino, custom USB, SD, externel EEPROM, or even network. 

It's architected in such a way that it does not dynamically load modules, but rather it is compiled seperately for each individual project. This preserves storage space and RAM. Modules are selected by defining various compiler preprocessor `#define` directives in the main program and including the kernel header file. Its modules may use Arduino libraries, and the kernel can be compiled within the Arduino IDE.

Each module has a `char <modulename>-init()` function and an `char <modulename>-loop()` function

##Useage (end users)

Users define the functions `char userInit(void)`, `char userLoop(void)`, and `void userPanic(void)`. 

`userInit` is called after the kernel and all modules initialize themselves, meaning all hardware should be available for the user to operate. It sets up anything the user needs; for example, initializing arrays or discovering communication peers could be done here.

`userLoop` performs all actions a user wishes to do inside the action loop.

`userPanic` contains actions performed on a kernel panic. This might include turning on a "FAULT" LED, etc. Note that drivers are not guaranteed to be available during a panic, so this should do something low-memory and simple, written without relying on drivers.

##Useage (module authors)

Modules define init and loop functions. Note that these functions MUST return a char value. They are called after the bootloader and kernel init/loop, but before the user init/loop.

Please respect KF_ALL_DEBUG when writing modules!

###Special cases

Modules which are bootloaders need to be called first, before anything else, to allow uploading of code. Generally they are written in assembly, and thus will be `extern`ed. The exception is the default bootloader, which simply returns.

##Kernel Flags
Kernel flags are `#define`s that change some aspect of the kernel. They take the form of `KF_<stage>_<name>`. The principal one that most users should be concerned with is `KF_ALL_DEBUG`. See [FLAGS.md](https://github.com/SilverWingedSeraph/AVR-MOS/blob/master/FLAGS.md) for details of other flags.

Note that modules may also have flags. These should be explained in their respective documentation.

###Debug Mode
KF_ALL_DEBUG sets debugging. Can be 0 (default), meaning no debug information; 1, meaning projected RAM usage and other performances characteristics are output (most useful for general users); 2, meaning only critical information is output; 3, meaning the majority of information is output; or 4, meaning all information is output. Note that this generally slows and bloats the binary rather a lot, since modules (should) respect this too!


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
+ 15: Bootloader is incompatible with this module.

\*NOTE: Retry only as many times as KF_INIT_RETRYS (default 3). Then panic.