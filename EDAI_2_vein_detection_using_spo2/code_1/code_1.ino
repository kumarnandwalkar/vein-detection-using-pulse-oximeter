#include <Wire.h>
#include "MAX30105.h"

// Create instances for each sensor
MAX30105 sensor1;
MAX30105 sensor2;
MAX30105 sensor3;

// Function to read SpO2 data from a sensor
void readSpO2Data(MAX30105 &sensor, float &spo2Value) {
  // Read the SpO2 value
  sensor.readTemperature();
  spo2Value = sensor.getINT2();
}

void setup() {
  // Start the I2C communication
  Wire.begin();

  // Initialize each sensor
  sensor1.begin(Wire, I2C_SPEED_FAST);
  sensor2.begin(Wire, I2C_SPEED_FAST);
  sensor3.begin(Wire, I2C_SPEED_FAST);
  
  // Configure settings for each sensor if needed
  sensor1.setup();
  sensor2.setup();
  sensor3.setup();
}

void loop() {
  // Variables to store the SpO2 values
  float spo2_1, spo2_2, spo2_3;

  // Read SpO2 data from sensor 1
  readSpO2Data(sensor1, spo2_1);
  Serial.print("Sensor 1 - SpO2: ");
  Serial.println(spo2_1);

  // Read SpO2 data from sensor 2
  readSpO2Data(sensor2, spo2_2);
  Serial.print("Sensor 2 - SpO2: ");
  Serial.println(spo2_2);

  // Read SpO2 data from sensor 3
  readSpO2Data(sensor3, spo2_3);
  Serial.print("Sensor 3 - SpO2: ");
  Serial.println(spo2_3);


  // Delay between readings
  delay(1000);


    // if ( sensor1 > 100)
    // {
    //   serial.print(" sensor 1 error!");
    // }
    // if ( sensor2 > 100)
    // {
    //   serial.print(" sensor 2 error!");
    // }
    // if ( sensor3 > 100)
    // {
    //   serial.print(" sensor 3 error!");
    // }

  

}