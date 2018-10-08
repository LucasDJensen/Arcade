const int startPin = 8;
const int restartPin = 9;

int startButtonState = 0;
int restartButtonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(startPin, INPUT);
  pinMode(restartPin, INPUT);
}

void loop() {
  startButtonState = digitalRead(startPin);
  restartButtonState = digitalRead(restartPin);

  if (startButtonState == HIGH) {
    Serial.println("start");
  }

  if (restartButtonState = HIGH) {
    Serial.println("restart");
  }
  
  delay(1000);
}