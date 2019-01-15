//Project 8 Digital Hourglass
//Build a digital hourglass with a tilt switch and 6 LEDs using Arduino's built in timer

const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 600000; //600000 milliseconds is 10 minutes

void setup() {
  //Declares the pins with LEDs as output
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime > interval) {
      previousTime = currentTime;
      digitalWrite(led, HIGH);
      led++;
  }

  switchState = digitalRead(switchPin);
  
  if (switchState != prevSwitchState) {
      for(int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
      }
    
    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
