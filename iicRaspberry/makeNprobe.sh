#!/bin/bash
nomeModulo="iicRaspberry.ko"

if [ -z "$I2C_ATIVADO" ]
then
	echo "Probing I2C modules"
#	modprobe i2c-bcm2708
#	modprobe i2c-dev
	lsmod | grep i2c
	i2cdetect -y 1
	export I2C_ATIVADO=1
fi


cd /home/pi/iicRaspberry/
echo 8 > /sys/bus/i2c/devices/i2c-1/delete_device
rmmod $nomeModulo
rmmod industrialio
make clean
make all
modprobe industrialio
insmod /home/pi/iicRaspberry/$nomeModulo
echo ARD 8 > /sys/bus/i2c/devices/i2c-1/new_device
cat /sys/bus/iio/devices/iio\:device0/in_voltage0_raw 
dmesg | tail -n 5
