//Project 5: Mood Cue
//Use a servo motor to make a mechanical gauge to point out what sort of mood you're in that day
//(Use a potentiometer to control a servo motor)

#include <Servo.h>
Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  myServo.attach(9);

  Serial.begin(9600);

}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179); //Change values from 0-1023 to values between 0-179
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(750);

}
