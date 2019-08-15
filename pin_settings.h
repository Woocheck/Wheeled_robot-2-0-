/*
 * pin_settings.h
 *
 * Created: 17.03.2019 21:34:45
 *  Author: Woocheck
*/

#ifndef __PIN_SETTINGS_H__
#define __PIN_SETTINGS_H__

struct Gpio {
    const int engineLeftA = 2;
    const int engineLeftB = 3;
    const int engineLeftEnable = 21;
    
    const int engineRightA = 23;
    const int engineRightB = 22;
    const int engineRightEnable = 25;
    
    const int encoderLeftA = 0;
    const int encoderLeftB = 9;
    
    const int encoderRightA = 1;
    const int encoderRightB = 4;
    
    const int frontSensor_1 = 6;
    const int frontSensor_2 = 26;
    const int frontSensor_3 = 27;
    const int frontSensor_4 = 28;
    const int frontSensor_5 = 29;

    const int rearSensor_1 = 10;
    const int rearSensor_2 = 10;
    const int rearSensor_3 = 11;
    const int rearSensor_4 = 31;
    const int rearSensor_5 = 31;

    const int OnButton = 24;

};


 
#endif /* PIN_SETTINGS_H_ */
