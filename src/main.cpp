/* 
 * File:   main.c
 * Author: daniel
 *
 * Created on 20. Juni 2010, 19:57
 */

#include <stdlib.h>
#include <stdio.h>
#include <usb.h>

#include "USBLamp.hpp"

//using namespace std;

int main(int argc, char** argv) {
    printf("start\n");
    USBLamp lamp = USBLamp();
    lamp.open();
    if (lamp.isConnected()) {
        while(1) {
            Color c = Color(0,0,127);
            lamp.setColor(c);
            sleep(1);
            c = Color(127,0,0);
            lamp.setColor(c);
            sleep(1);
            c = Color(0,60,60);
            lamp.setColor(c);
            sleep(1);
        }
        lamp.switchOff();
        //lamp.sendInterrupt();
        lamp.close();
    } else {
        printf("no lamp found\n");
    }
    printf("end\n");

    return 0;
}