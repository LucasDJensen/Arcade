//Master
#include <Wire.h>

void setup() {
  Wire.begin(0);
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
}

//function that executes whenever data is received from slaves
//this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  String str = "";
  while (Wire.available()) { 
    char c = Wire.read(); // receive byte as a character
    str += String(c);
  }
  Serial.println(str);
}

