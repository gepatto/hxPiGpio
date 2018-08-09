#include "piGpio.h"
#include <wiringPi.h> 

namespace pigpio {
	
	int SampleMethod(int inputValue) {	
		return inputValue * 100;
	}
	
}