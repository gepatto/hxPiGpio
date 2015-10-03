# hxPiGpio
Haxe/OpenFL extension for using the GPIO Ports on the Rapberry Pi

#Status: under development

Requires wiringPi 2.29 to be installed.

add the following file to /etc/udev/rules.d/20-gpio.rules

> SUBSYSTEM=="bcm2835-gpiomem", KERNEL=="gpiomem", GROUP="gpio", MODE="0660"
> SUBSYSTEM=="gpio", KERNEL=="gpiochip*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys/class/gpio/export /sys/class/gpio/unexport ; chmod 220 /sys/class/gpio/export /sys/class/gpio/unexport'"
> SUBSYSTEM=="gpio", KERNEL=="gpio*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value ; chmod 660 /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value'"

add the following environment variable:
> export WIRINGPI_GPIOMEM=1

[ wiringpi reference] (http://wiringpi.com/wiringpi-update-to-2-29/)
