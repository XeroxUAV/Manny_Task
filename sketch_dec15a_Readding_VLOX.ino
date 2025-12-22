#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  Wire.begin();  // Initialize I2C bus
  if (!sensor.init()) {
    Serial.println("Failed to detect VL53L0X!");
  }
  // sensor.startContinuous();
  sensor.setTimeout(1000);
}

void loop() 
{
  // Read distance in mm
  int distance = 1;
  Serial.println(1);
  // Check for timeout
  if (sensor.timeoutOccurred()) 
  {
    digitalWrite(2, HIGH);
    Serial.println("Sensor timeout!");
    return;
  }
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");
  digitalWrite(2, HIGH);
  delay(1000); // Optional delay
  digitalWrite(2,LOW);
}
