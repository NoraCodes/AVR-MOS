#Kernel Configuration Flags
Note that many of these are not true flags.

##Global flags (KF_ALL_x)
KF_ALL_DEBUG = Sets debug mode. Can be 0 (default), meaning no debug information; 1, meaning projected RAM usage and other performances characteristics are output; 2, meaning only critical information is output; 3, meaning the majority of information is output; or 4, meaning all information is output. Note that this generally slows and bloats the binary rather a lot, since modules (should) respect this too!


##Initialization flags (KF_INIT_x)
KF_INIT_RETRYS = Governs the number of retries from recoverable errors before the kernel panics.


##Execution flags (KF_LOOP_x)