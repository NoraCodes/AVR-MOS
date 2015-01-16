/*
modules/pinraw/pinraw.c
*/

#include pinraw_config.h //Configuration file

typedef struct {
	unsigned char pin0mode : 1 ;
	unsigned char pin1mode : 1 ;
	unsigned char pin2mode : 1 ;
	unsigned char pin3mode : 1 ;	

	unsigned char pin0stat : 1 ;
	unsigned char pin1stat : 1 ;
	unsigned char pin2stat : 1 ;
	unsigned char pin3stat : 1 ;	

} pinraw_4pins_struct; //Used to store the mode and state of 4 pins in exactly 8 bits.

char pinraw_init(void){
	//Initialization stuff here!
	return 0;
}

char pinraw_loop(void){
	//Loopy stuff here!
	return 0;
}
