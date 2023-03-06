# hxPiGpio
Haxe/OpenFL extension for using the GPIO Ports on the Rapberry Pi

# Status: Deprecated.

# WiringPi is no longer maintained, so unfortunately this means the end of this this extension 

Requires wiringPi 2.29 to be installed.  
*Not all methods in WiringPi are exposed!*

# Installation
cd into a directory where you store haxe modules that are not in the haxelib repo

    git clone https://github.com/gepatto/hxPiGpio.git
    haxelib dev hxPiGpio hxPiGpio/
    cd hxPiGpio
    lime rebuild . rpi -clean

# example usage   
add the following to your openfl project.xml  
`<haxelib name="hxPiGpio" />`  

read a digital input

    PiGpio.wiringPiSetupGpio();
    PiGpio.pinMode( 18, PiGpio.INPUT ); // 18 is gpio18
    var pinValue = PiGpio.digitalRead(18);
    trace(pinValue);

# Requirements
make a file called /etc/udev/rules.d/20-gpio.rules with the following file contents

> SUBSYSTEM=="bcm2835-gpiomem", KERNEL=="gpiomem", GROUP="gpio", MODE="0660"
> SUBSYSTEM=="gpio", KERNEL=="gpiochip*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys/class/gpio/export /sys/class/gpio/unexport ; chmod 220 /sys/class/gpio/export /sys/class/gpio/unexport'"
> SUBSYSTEM=="gpio", KERNEL=="gpio*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value ; chmod 660 /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value'"

add the following environment variable:
> export WIRINGPI_GPIOMEM=1

[ wiringpi reference] (http://wiringpi.com/wiringpi-update-to-2-29/)
