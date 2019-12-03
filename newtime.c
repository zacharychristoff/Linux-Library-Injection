#define _GNU_SOURCE

#include <stdio.h>
#include <time.h>
#include <dlfcn.h>
/*
Zach Christoff
 */
int count = 0;

time_t time(time_t *tloc){
	if(count == 0){
		time_t seconds = 1564605772;
		if(tloc != NULL){
			*tloc = seconds;
		}
		count = 1;
		return(seconds);
	}
	else{
		time_t *(*orig_time)(time_t *tloc);
		orig_time = dlsym(RTLD_NEXT, "time");
		time_t current_seconds;
		current_seconds = (time_t) (*orig_time)(tloc);
		return current_seconds;
	}
}
