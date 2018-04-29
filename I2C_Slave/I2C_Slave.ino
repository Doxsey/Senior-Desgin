// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

byte CA2 = 0;
byte CA1 = 0;
byte CA0 = 0;

void I2C_Action(int);

void setup() {
  Wire.begin(8);                // join i2c bus with address #100
  Wire.onReceive(I2C_Action);
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(9, HIGH);
}

void loop() {
 delay(100);
}

void I2C_Action(int nBytes)
{
  digitalWrite(8, HIGH);
  byte I2C_Data = Wire.read();
  Serial.print("I2C Data Packet: ");
  Serial.println(I2C_Data, BIN);

  CA2 = (I2C_Data & 110000) >> 4;
  Serial.print("CA2: ");
  Serial.println(CA2, BIN);

  CA1 = (I2C_Data & 001100) >> 2;
  Serial.print("CA1: ");
  Serial.println(CA1, BIN);

  CA0 = (I2C_Data & 11);
  Serial.print("CA0: ");
  Serial.println(CA0, BIN);
  
  while(Wire.available()) //Get rest of data to clear the read buffer. We don't care about the rest of the data
  {
    Wire.read();
  }
  return;
}
