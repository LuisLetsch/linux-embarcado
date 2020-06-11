#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <linux/delay.h>

int main(int argc,char *argv[]){
    FILE* fp ;
    FILE* fp2 ;
    FILE* fp3 ;
    char buffer[15];
    int raw1, raw2, i;
    float scale, voltage1, voltage2;



	for(i=0;i<25;i++){
    fp = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");
    if (!fp) { printf("Could not open source file\n"); exit(-1); }

    fp2 = fopen("/sys/bus/iio/devices/iio:device0/in_voltage1_raw", "r");
    if (!fp2) { printf("Could not open source file\n"); exit(-1); }

    fp3 = fopen("/sys/bus/iio/devices/iio:device0/in_voltage_scale", "r");
    if (!fp3) { printf("Could not open source file\n"); exit(-1); };

		fscanf(fp, "%s", buffer);
//		printf("Raw Voltage 1: %s\n", buffer);
		raw1 = atoi(buffer);


		fscanf(fp2, "%s", buffer);
//		printf("Raw Voltage 2: %s\n", buffer);
		raw2 = atoi(buffer);


		fscanf(fp3, "%s", buffer);
//		printf("Scale: %s\n", buffer);
		scale = atof(buffer);


		voltage1 = raw1 * scale;
		voltage2 = raw2 * scale;

		sprintf(buffer, "%.1f", voltage1);
		printf("Voltage 1: %s V\n", buffer);
		sprintf(buffer, "%.1f", voltage2);
		printf("Voltage 2: %s V\n", buffer);
//		memset(buffer, 0, sizeof (buffer));
		sleep(1);
//		delay(1);     //teste
    fclose(fp);
    fclose(fp2);
    fclose(fp3);
	}


}
