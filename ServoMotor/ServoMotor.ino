#include <Servo.h>
Servo EduServo;

void setup() {
  // put your setup code here, to run once:
  EduServo.attach(4);

}

void loop() {
  // put your main code here, to run repeatedly:
  EduServo.write(0);
  delay(1000);
  EduServo.write(90);
  delay(1000);
  EduServo.write(180);
  delay(1000);
}
