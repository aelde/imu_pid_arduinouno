#include "gyro.h"

// gyro setup function v1
void gyro_setup(void) {
    Wire.beginTransmission(0x68);
    Wire.write(0x6B);
    Wire.write(0x00);
    Wire.endTransmission();
}

// gyro signals is not stable even i don't move the sensors 
void gyro_signals(void) {
    Wire.beginTransmission(0x68);
    Wire.write(0x1A);
    Wire.write(0x05);
    Wire.endTransmission();
    Wire.beginTransmission(0x68);
    Wire.write(0x1B);
    Wire.write(0x8);
    Wire.endTransmission();
    Wire.beginTransmission(0x68);
    Wire.write(0x43);
    Wire.endTransmission();
    Wire.requestFrom(0x68, 6);
    int16_t GyroX = Wire.read() << 8 | Wire.read();
    int16_t GyroY = Wire.read() << 8 | Wire.read();
    int16_t GyroZ = Wire.read() << 8 | Wire.read();
    RateRoll = (float)GyroX / 65.5;
    RatePitch = (float)GyroY / 65.5;
    RateYaw = (float)GyroZ / 65.5;
}

// make new setup gyro to make more stable (v2)
void gyro_setup_v_2(void) {
    Wire.beginTransmission(0x68); 
    Wire.write(0x6B);
    Wire.write(0x00);
    Wire.endTransmission();
    for (RateCalibrationNumber=0; RateCalibrationNumber<2000; RateCalibrationNumber ++) {
        gyro_signals();
        RateCalibrationRoll+=RateRoll;
        RateCalibrationPitch+=RatePitch;
        RateCalibrationYaw+=RateYaw;
        delay(1);
    }
    RateCalibrationRoll/=2000;
    RateCalibrationPitch/=2000;
    RateCalibrationYaw/=2000;   
}