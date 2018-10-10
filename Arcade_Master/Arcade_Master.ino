//Master
#include <Wire.h>
String lastSlave;
float lastSlavePercent;
bool skip;

void setup() {
  Wire.begin(0);
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(19200);           // start serial for output
  lastSlave = "";
  lastSlavePercent = 0;
  skip = false;
}

void loop() {
}

//function that executes whenever data is received from slaves
//this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  String str = "";
  float percent = 0;
  String slave = "";

  str = readSlave();
  percent = getValue(str, ' ', 0).toFloat();
  slave = getValue(str, ' ', 1);

  if (!skip) {
    float sendValue = 0;
    float degreeDiff = 0;
    if (slave.equals(lastSlave) || lastSlave.equals("")) {
      sendValue = percent;
      lastSlave = slave;
      lastSlavePercent = percent;
    } else {
      if (percent >= lastSlavePercent) {
        degreeDiff = percent - lastSlavePercent;
      } else {
        degreeDiff = lastSlavePercent - percent;
      }
      float degreeBase = (percent + lastSlavePercent) / 2;

      if (degreeDiff <= 180) {
        if (degreeBase <= 180) {
          sendValue = degreeBase + 180;
        } else {
          sendValue = degreeBase - 180;
        }
      } else {
        sendValue = degreeBase;
      }
      lastSlave = "";
      lastSlavePercent = 0;
      skip = true;
    }
    Serial.println(sendValue);
  } else {
    if (slave.equals(lastSlave) || lastSlave.equals("")) {
      lastSlave = slave;
      lastSlavePercent = percent;
      skip = false;
    }
  }
}

String readSlave() {
  String str = "";
  while (Wire.available()) {
    char c = Wire.read(); // receive byte as a character
    str += String(c);
  }
  return str;
}

// https://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
