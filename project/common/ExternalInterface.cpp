#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif


#include <hx/CFFI.h>
#include "Utils.h"
#include <wiringPi.h> 

using namespace pigpio;

static value pigpio_sample_method (value inputValue) {
	int returnValue = SampleMethod(val_int(inputValue));
	return alloc_int(returnValue);
}
DEFINE_PRIM (pigpio_sample_method, 1);


/* ------------------
|  SETUP FUNCTIONS 
|  ------------------
*/
static void pigpio_wiringPiSetup () {
	wiringPiSetup();
}
DEFINE_PRIM (pigpio_wiringPiSetup, 0);


static void pigpio_wiringPiSetupSys () {
	wiringPiSetupSys();
}
DEFINE_PRIM (pigpio_wiringPiSetupSys, 0);


static void pigpio_wiringPiSetupGpio () {
	wiringPiSetupGpio();
}
DEFINE_PRIM (pigpio_wiringPiSetupGpio, 0);


static void pigpio_wiringPiSetupPhys () {
	wiringPiSetupPhys();
}
DEFINE_PRIM (pigpio_wiringPiSetupPhys, 0);

/* ------------------
|  PINMODE FUNCTIONS 
|  ------------------
*/
static void pigpio_pinMode (value pin, value pinModeValue) {
	pinMode( val_int(pin) , val_int(pinModeValue) );
}
DEFINE_PRIM (pigpio_pinMode, 2);


static void pigpio_pinModeAlt (value pin, value pinModeValue) {
	pinModeAlt( val_int(pin) , val_int(pinModeValue) );
}
DEFINE_PRIM (pigpio_pinModeAlt, 2);


static void pigpio_pullUpDnControl (value pin, value pinModeValue) {
	pullUpDnControl( val_int(pin) , val_int(pinModeValue) );
}
DEFINE_PRIM (pigpio_pullUpDnControl, 2);


/* ------------------
|  READ WRITE FUNCTIONS 
|  ------------------
*/
static value pigpio_digitalRead (value pin) {
	int returnValue = digitalRead(val_int(pin));
	return alloc_int(returnValue);
}
DEFINE_PRIM (pigpio_digitalRead, 1);


static void pigpio_digitalWrite (value pin, value pinValue) {
	digitalWrite( val_int(pin), val_int(pinValue) );
}
DEFINE_PRIM (pigpio_digitalWrite, 2);

static value pigpio_analogRead(value pin) {
	int returnValue = analogRead (val_int(pin));
	return alloc_int(returnValue);
}
DEFINE_PRIM (pigpio_analogRead, 1);

static void pigpio_analogWrite (value pin, value pinValue) {
	analogWrite( val_int(pin), val_int(pinValue));
}
DEFINE_PRIM (pigpio_analogWrite, 2);


static void pigpio_pwmWrite (value pin, value pinValue) {
	pwmWrite(val_int(pin), val_int(pinValue));
}
DEFINE_PRIM (pigpio_pwmWrite, 2);


/* ------------------
|  
|  ------------------
*/
extern "C" void pigpio_main () {
	
	val_int(0); // Fix Neko init
	
}
DEFINE_ENTRY_POINT (pigpio_main);



extern "C" int pigpio_register_prims () { return 0; }