//Slave 1
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
  Wire.begin(1);
//  Serial.begin(9600);
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
  long percent = 0;
  int counter = 0;

  duration = getDuration(trigPin1, echoPin1);
  if (validateForTransmit(duration)) {
    // distance = (duration / 2) / 29.1;
    if (duration != 0) {
      percent += 195;
      counter++;
    }
  }

  duration = getDuration(trigPin2, echoPin2);
  if (validateForTransmit(duration)) {
    // distance = (duration / 2) / 29.1;
    if (duration != 0) {
      percent += 225;
      counter++;
    }
  }

  duration = getDuration(trigPin3, echoPin3);
  if (validateForTransmit(duration)) {
    // distance = (duration / 2) / 29.1;
    if (duration != 0) {
      percent += 255;
      counter++;
    }
  }

  duration = getDuration(trigPin4, echoPin4);
  if (validateForTransmit(duration)) {
    // distance = (duration / 2) / 29.1;
    if (duration != 0) {
      percent += 285;
      counter++;
    }
  }

  duration = getDuration(trigPin5, echoPin5);
  if (validateForTransmit(duration)) {
    // distance = (duration / 2) / 29.1;
    if (duration != 0) {
      percent += 315;
      counter++;
    }
  }

  duration = getDuration(trigPin6, echoPin6);
  if (validateForTransmit(duration)) {
    // distance = (duration / 2) / 29.1;
    if (duration != 0) {
      percent += 345;
      counter++;
    }
  }
  if (percent != 0) {
    percent = percent / counter;
    String str = String(percent) + " 1";
//    Serial.println(str);
    transmit(str);
  }
  delay(20);

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
  digitalWrite(triggerPin, LOW );
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
