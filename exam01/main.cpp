// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library
//
#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
PwmOut PWM1(D6);

AnalogIn Ain(D7);
AnalogOut Aout(DAC0_OUT);
float ADCdata0;
Serial pc(USBTX, USBRX);
int sample = 128;
float ADCdata[128];

int main() {

    uLCD.text_width(2); //1.5X size text
    uLCD.text_height(2);
    uLCD.color(BLUE);
    uLCD.printf("\n106061240");
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    for (int i = 50; i < 60; i++)
        uLCD.line(50, i , 59, i, 0xffff);
    

    int j = 0;
    float time = 0;
    int k = 0;
    while (1) {
    
        float i = 0;
        while (i <= 1) {
            PWM1.period(0.001);
            PWM1 = i;
            Ain = PWM1;
            ADCdata[j] = Ain;
            wait(1. / sample);
            time += 1./sample;
            if (time > 0.1) {
                time -= 0.1;
                i += 0.1;
            }
            pc.printf("%1.3f\r\n", ADCdata[k]);
            k++;
        }
        i = 0.9;
        while (i >= 0) {
            PWM1.period(0.001);
            PWM1 = i;
            Ain = PWM1;
            ADCdata[j] = Ain;
            wait(1. / sample);
            time += 1./sample;
            if (time > 0.1) {
                time -=0.1; 
                i -= 0.1;
            }
            pc.printf("%1.3f\r\n", ADCdata[k]);
            k++;
        }
    }

}