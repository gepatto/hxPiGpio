/*
 * ttp229.cpp:
 *	Extend wiringPi with the ttp229 capacitive input
 */
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>

#include "ttp229.h"
#define	I2C_ADDRESS	0x57

static uint16_t PINSPRESSED ;

/*
 * read16:
 *	Quick hack to read the 16-bit data with the correct endian
 *********************************************************************************
 */
uint16_t read16 (int fd, int reg)
{
  return (wiringPiI2CReadReg8 (fd, reg) <<  8) | wiringPiI2CReadReg8 (fd, reg + 1) ;
}

/*
 * readPins:
 *********************************************************************************
 */
static void readPins (int fd)
{
    uint8_t data[2] ;

    //read 2 bytes  (1 byte per 8 pins)
    read(fd, data, 2);

    // shift first byte so we can send all channels as 1 Int;
    PINSPRESSED = data[0]<<8 | data[1];
}


/*
 * myAnalogRead:
 *********************************************************************************
 */
static int myAnalogRead (struct wiringPiNodeStruct *node, int pin)
{
    readPins(node->fd) ;
    return PINSPRESSED;
}

/*
 * ttp229Setup:
 *	Create a new wiringPi device node for an ttp229 16 pins capacitive touch on the Pi's
 *	I2C interface.
 *********************************************************************************
 */

int ttp229Setup (const int pinBase)
{
  int fd ;
  struct wiringPiNodeStruct *node ;

  if ((fd = wiringPiI2CSetup (I2C_ADDRESS)) < 0)
    return FALSE ;
  
  node = wiringPiNewNode (pinBase, 1) ;

  node->fd          = fd ;
  node->analogRead = myAnalogRead ;

  readPins(node->fd) ;

  return TRUE ;
}
