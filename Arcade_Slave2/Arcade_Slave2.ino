//Slave 2
#include <Wire.h>

#define trigPin1 3
#define echoPin1 2
#define trigPin2 5
#define echoPin2 4
#define trigPin3 7
#define echoPin3 6
#define trigPin4 9
#define echoPin4 8
#define trigPin5 11
#define echoPin5 10
#define trigPin6 13
#define echoPin6 12

void setup() {
  Wire.begin(2);
//  Serial.begin(19200);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);
}

void loop() {
  long duration, distance;

  duration = getDuration(trigPin1, echoPin1);
  if (validateForTransmit(duration)) {
    distance = (duration/2) / 29.1;
    if(distance != 0) {
      transmit(String(distance) + " cm 7");
    }
  }

  duration = getDuration(trigPin2, echoPin2);
  if (validateForTransmit(duration)) {
    distance = (duration/2) / 29.1;
    if(distance != 0) {
      transmit(String(distance) + " cm 8");
    }
  }

  duration = getDuration(trigPin3, echoPin3);
  if (validateForTransmit(duration)) {
    distance = (duration/2) / 29.1;
    if(distance != 0) {
      transmit(String(distance) + " cm 9");
    }
  }

  duration = getDuration(trigPin4, echoPin4);
  if (validateForTransmit(duration)) {
    distance = (duration/2) / 29.1;
    if(distance != 0) {
      transmit(String(distance) + " cm 10");
    }
  }

  duration = getDuration(trigPin5, echoPin5);
  if (validateForTransmit(duration)) {
    distance = (duration/2) / 29.1;
    if(distance != 0) {
      transmit(String(distance) + " cm 11");
    }
  }

  duration = getDuration(trigPin6, echoPin6);
  if (validateForTransmit(duration)) {
    distance = (duration/2) / 29.1;
    if(distance != 0) {
      transmit(String(distance) + " cm 12");
    }
  }

  delay(35);

}

boolean validateForTransmit(long duration) {
  boolean isOk = false;

  if (duration < 4000) {
      isOk = true;
  }
  return isOk;
}

long getDuration(uint8_t triggerPin, uint8_t echoPin) {
  long duration;
  digitalWrite(triggerPin, LOW );  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH, 8000);
  return duration;
}

void transmit(String data) {
  Wire.beginTransmission(0);
  Wire.write(data.c_str());
  Wire.endTransmission();
}
