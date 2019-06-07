#include <Arduino.h>
#include "DRV8834.h"
#include "GY_85.h"
#include <Wire.h>
#include <AutoPID.h>
#include "math.h"

#define MOTOR_STEPS 200
#define RPM 120
#define DIRL 4
#define STEPL 6
#define DIRR 2
#define STEPR 3
#define SLEEP 13 // optional (just delete SLEEP from everywhere if not used)
#define M0 10
#define M1 11

#define OUTPUT_MIN -200
#define OUTPUT_MAX 200
#define KP .12
#define KI .0003
#define KD 0

GY_85 GY85;     //create the object
DRV8834 stepperR(MOTOR_STEPS, DIRR, STEPR, SLEEP, M0, M1);
DRV8834 stepperL(MOTOR_STEPS, DIRL, STEPL, SLEEP, M0, M1);

int ax,ay, az;
double angle, setPoint, outputVal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);
  Wire.begin();
  delay(10);
  GY85.init();
  delay(10);
  stepperR.begin(RPM);
  stepperR.enable();
  stepperL.begin(RPM);
  stepperL.enable();
  
}


void stepControl(double input)
{
  if(input >= 0)
    {
      stepperR.setRPM(float(abs(input)));
      stepperL.setRPM(float(abs(input)));
      stepperR.rotate(5);
      stepperL.rotate(5); 
    }
    else
    {
      stepperR.setRPM(float(abs(input)));
      stepperL.setRPM(float(abs(input)));
      stepperR.rotate(-5);
      stepperL.rotate(-5); 
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  ax = GY85.accelerometer_x( GY85.readFromAccelerometer() );
  ay = GY85.accelerometer_y( GY85.readFromAccelerometer() );
  az = GY85.accelerometer_z( GY85.readFromAccelerometer() );
  angle =  atan2(ay,az);
  
}
