// this gyro.h file

#ifndef GYRO_H
#define GYRO_H
// include files
#include <Arduino.h>
#include <Wire.h>


// shared variables
extern float RateRoll, RatePitch, RateYaw, RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;
extern int RateCalibrationNumber;

// public function prototypes
void gyro_signals(void);
void gyro_setup(void);
void gyro_setup_v_2(void);

#endif 