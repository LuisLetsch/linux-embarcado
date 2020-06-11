#!/bin/bash


ip_Do_Rpi=""


nomeCodigo="iicRaspberry.c"

if [ "$#" -ne 1 ]
then
	scp $nomeCodigo root@$ip_Do_Rpi:/home/pi/iicRaspberry/
	ssh root@$ip_Do_Rpi  '/home/pi/iicRaspberry/makeNprobe.sh'
else
	scp $1 root@$ip_Do_Rpi:/home/pi/iicRaspberry/
fi
