//Project 14 Tweak the Arduino Logo
//Use serial communication and a potentiometer to control a 
//program on your computer which allows the hue of the Arduino
//logo to change 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write(analogRead(A0)/4); //Ensures that serial.write() sends values between 0 and 255
  delay(100);

}
