/*
kernel.c
AVR MOS Kernel main file - ONLY THIS should be included in the Arduino sketch by most users.
Note: this is an Arduino sketch!
*/

#include "headers/kconfig.h" //Include kernel headers. These allow configuration of the kernel.
#include "headers/modules.h" //Include module selection setup.

//Module PinRaw
#if MOD_PINRAW
	#include "modules/pinraw/pinraw.c"
#endif

//prototype user callback functions.
char userInit(void);
char userLoop(void);
void userPanic(void);

//prototype kernel functions
inline void kCheckErrorState(void);
void kPanic(void);

//kernel global states
unsigned char kErrorState = 0; //Records the kernel error state
unsigned char kRetries    = 0; //Number of retries up to this point
unsigned char kRetry      = 0; //Do we need to retry this time? TODO: Make this work!

void setup(void){
	
	#if MOD_PINRAW
		kErrorState = pinraw-init(); //Initialize the PinRaw module.
	#endif
}

void loop(void){
	
	#if MOD_PINRAW
		kErrorState = pinraw-loop(); //Update the PinRaw module
	#endif
}

inline void kCheckErrorState(void){ //Checks the kernel error state and returns if it is 0, else calls the appropriate action.
	if (kErrorState == 0) { //No error!
		return;		
	}
	elseif (kErrorState < 3) { //Recoverable errors.
		kRetry = 1; //Set the retry variable to indicate to loop() that we need to retry
		return;
	}
	else{
		kPanic(); //Something is badly broken... PANIC!!	
	}
}

void kPanic(void){ //Kernel panic!
	userPanic(); //User panic instructions
	while(1){
		asm("nop"); //Do nothing.	
	}
}