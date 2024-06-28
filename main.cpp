#include "mbed.h"
#include "HEPTA_EPS.h"
#include "HEPTA_SENSOR.h"
 
RawSerial pc(USBTX,USBRX,9600);
HEPTA_EPS eps(p16,p26);
HEPTA_SENSOR sensor(p17,
                  p28,p27,0x19,0x69,0x13,
                  p13, p14,p25,p24);
Timer sattime;

int main(){
    sattime.start();
    float ax,ay,az;
    float gx,gy,gz;
    float mx,my,mz;
    pc.printf("9axis Mode\r\n");
    for(int i = 0; i<50; i++) {
        sensor.sen_acc(&ax,&ay,&az);
        sensor.sen_gyro(&gx,&gy,&gz);
        sensor.sen_mag(&mx,&my,&mz);
        pc.printf(" Time = %.2f [s]",sattime.read());
        pc.printf(" acc : %f,%f,%f",ax,ay,az);
        pc.printf(" gyro: %f,%f,%f",gx,gy,gz);
        pc.printf(" mag : %f,%f,%f\r\n",mx,my,mz);
        wait(0.5);
    }
}