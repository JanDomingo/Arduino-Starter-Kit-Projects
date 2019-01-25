import processing.serial.*;
Serial myPort;

PImage logo;

int bgcolor = 0; //background color

void setup() {
  colorMode(HSB, 255); //HSB stands for Hue, Saturation, and Brightness
                       //The potentiometer will adjust the hue
  logo = loadImage("https://www.arduino.cc/en/pub/skins/arduinoWide/img/logo.png");
  size(400, 200);

  println("Available serial ports: ");
  println(Serial.list());

myPort = new Serial(this, Serial.list()[6], 9600);
}

void draw() {
  if (myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  
  background(bgcolor, 255, 255);
  image (logo, 0, 0);
}

  
