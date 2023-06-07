#include <Wire.h>
#include "MAX30105.h"

MAX30105 sensor1;
MAX30105 sensor2;
MAX30105 sensor3;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize the sensors
  sensor1.begin();
  sensor2.begin();
  sensor3.begin();
}

void loop() {
  // Read the SPO2 values from the sensors
  int spo21 = sensor1.readSPO2();
  int spo22 = sensor2.readSPO2();
  int spo23 = sensor3.readSPO2();

  // Print the SPO2 values to the serial monitor
  Serial.print("SPO21: ");
  Serial.print(spo21);
  Serial.print(", SPO22: ");
  Serial.print(spo22);
  Serial.print(", SPO23: ");
  Serial.println(spo23);

  // Delay for 1 second
  delay(1000);
}