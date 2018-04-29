#include <Wire.h>

int CA2 = 0;
int CA1 = 0;
int CA0 = 0;



void I2C_Action(int);

void setup() {
  Wire.begin(8);                // join i2c bus with address #100
  Wire.onReceive(I2C_Action);
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  
}

void loop() {
 delay(100);
}

void I2C_Action(int nBytes)
{
  digitalWrite(8, HIGH);
  byte I2C_Data = Wire.read();
  
  CA2 = (I2C_Data & 110000) >> 4;
  CA1 = (I2C_Data & 001100) >> 2;
  CA0 = (I2C_Data & 11);
  
  Serial.print("I2C Data Packet: ");
  Serial.println(I2C_Data, BIN);
  
switch (CA2) {
	case 0:
		Serial.print("CA2: ");
		Serial.println("LOW");
		break;
	case 2:
		Serial.print("CA2: ");
		Serial.println("FLOAT");
		break;
	case 3:
		Serial.print("CA2: ");
		Serial.println("HIGH");
		break;
	default:
		break;
}
  
switch (CA1) {
	case 0:
		Serial.print("CA1: ");
		Serial.println("LOW");
		break;
	case 2:
		Serial.print("CA1: ");
		Serial.println("FLOAT");
		break;
	case 3:
		Serial.print("CA1: ");
		Serial.println("HIGH");
		
		break;
	default:
		break;
	
	}  

switch (CA0) {
	case 0:
		Serial.print("CA0: ");
		Serial.println("LOW");
		break;
	case 2:
		Serial.print("CA0: ");
		Serial.println("FLOAT");
		break;
	case 3:
		Serial.print("CA0: ");
		Serial.println("HIGH");
		
		break;
	default:
		break;
	
	} 	
  

  
  while(Wire.available()) //Get rest of data to clear the read buffer. We don't care about the rest of the data
  {
    Wire.read();
  }
  return;
}
