// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AD5259
// This code is designed to work with the AD5259_I2CPOT_10K I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Temperature?sku=ADT75_I2CS#tabs-0-product_tabset-2

#include<Wire.h>

// AD5259 I2C address is 0x18(24)
#define Addr 0x18
void setup()
{
  // Initialise I2C communication as Master
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send command byte
  Wire.write(0x00);
  // Input resistance value, 0x80(128)
  Wire.write(0x80);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(300);
}

void loop()
{
  unsigned int data;

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Send command byte
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data = Wire.read();
  }

  // Convert the data
  float resistance = (data / 256.0 ) * 10.0;

  // Output data to serial monitor
  Serial.print("Resistance : ");
  Serial.print(resistance);
  Serial.println(" K");
  delay(500);
}
