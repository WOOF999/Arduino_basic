
#include <Stepper.h>

const int stepsPerRevolution =2048;
Stepper myStepper(stepsPerRevolution,11,9,10,8);

void setup() {
  myStepper.setSpeed(14);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("counterclockwise");
  //myStepper.step(stepsPerRevolution);
  delay(1000);

  Serial.println("clockwise");
  //myStepper.step(-stepsPerRevolution);
  delay(1000);

}
