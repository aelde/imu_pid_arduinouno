#include "main.h"
#include "gyro.h"

float RateRoll, RatePitch, RateYaw, RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;
int RateCalibrationNumber;

void setup() {
    Serial.begin(115200);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    Wire.setClock(400000);
    Wire.begin();
    delay(250);
    gyro_setup_v_2();
}


// void loop() {
//     gyro_signals();
//     Serial.print("Roll rate [°/s]= ");
//     Serial.print(RateRoll);
//     Serial.print(" Pitch Rate [°/s]= ");
//     Serial.print(RatePitch);
//     Serial.print(" Yaw Rate [°/s]= ");
//     Serial.println(RateYaw);
//     delay(500);
// }

// new loop function v2
void loop() {
  gyro_signals();
  RateRoll-=RateCalibrationRoll;
  RatePitch-=RateCalibrationPitch;
  RateYaw-=RateCalibrationYaw;
  Serial.print("Roll rate [°/s]= ");
  Serial.print(RateRoll); 
  Serial.print(" Pitch Rate [°/s]= ");
  Serial.print(RatePitch);
  Serial.print(" Yaw Rate [°/s]= ");
  Serial.println(RateYaw);
  delay(50);
}