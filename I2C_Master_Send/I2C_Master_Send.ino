#include <Wire.h>

#define I2C_Low 0b00000000 //00 denotes to set the output pin to low
#define I2C_High 0b00000011 //11 denotes to set the output pin to high
#define I2C_Float 0b00000010 //10 denotes to set the pin to and input, causing it to be a floating voltage


byte CA2 = I2C_High; //Set the CA2 bit address here (Address 100 is reserved for the ATMega IC)
byte CA1 = 0b01;
byte CA0 = I2C_High;

byte I2C_Data = 0; //This is the data packet to send to the I2C slave.

void setup() 
{
	//Serial.begin(9600);
	I2C_Data = (I2C_Data | CA2) << 2;
	I2C_Data = (I2C_Data | CA1) << 2;
	I2C_Data = (I2C_Data | CA0);

	Wire.begin(); // join i2c bus with address of 1

	Wire.beginTransmission(100); // transmit to device #100 (0x64)
	Wire.write(I2C_Data);       // sends I2C_Data byte  
	Wire.endTransmission();     // stop transmitting
 
}

void loop() 
{

}

