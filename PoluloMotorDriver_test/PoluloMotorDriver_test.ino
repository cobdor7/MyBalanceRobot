/* Simple step test for Pololu stepper motor driver carriers 
This code can be used with the A4988, DRV8825, DRV8824, and 
DRV8834 Pololu stepper motor driver carriers.  It sends a pulse 
every 500 ms to the STEP pin of a stepper motor driver that is 
connected to pin 2 and changes the direction of the stepper motor
every 50 steps by toggling pin 3. */

#define STEP_PINR 6
#define DIR_PINR 4
 
#define STEP_PINL 3
#define DIR_PINL 2
 
bool dirHigh;
 
void setup()
{
  dirHigh = true;
  digitalWrite(DIR_PINL, HIGH);
  digitalWrite(STEP_PINL, LOW);
  pinMode(DIR_PINL, OUTPUT);
  pinMode(STEP_PINL, OUTPUT);

   digitalWrite(DIR_PINR, HIGH);
  digitalWrite(STEP_PINR, LOW);
  pinMode(DIR_PINR, OUTPUT);
  pinMode(STEP_PINR, OUTPUT);
}
 
void loop()
{
  // Toggle the DIR pin to change direction.
  if(dirHigh)
  {
    dirHigh = false;
    digitalWrite(DIR_PINR, LOW);
    digitalWrite(DIR_PINL, LOW);
  }
  else
  {
    dirHigh = true;
    digitalWrite(DIR_PINR, HIGH);
    digitalWrite(DIR_PINL, HIGH);
  }
 
  // Step the motor 50 times before changing direction again.
  for(int i = 0; i < 100; i++)
  {
    // Trigger the motor to take one step.
    digitalWrite(STEP_PINR, HIGH);
    digitalWrite(STEP_PINL, HIGH);
    delay(20);
    digitalWrite(STEP_PINR, LOW);
    digitalWrite(STEP_PINL, LOW);
    delay(1);
  }
}
