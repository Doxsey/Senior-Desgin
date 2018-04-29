#include <Wire.h>

#define CA2_Pin 9
#define CA1_Pin 8
#define CA0_Pin 7

byte CA2 = 0;
byte CA1 = 0;
byte CA0 = 0;

void I2C_Action(int);

void setup() {
  Wire.begin(100);                // join i2c bus with address #100
  Wire.onReceive(I2C_Action);
  ////Serial.begin(9600);	//For debuggin purposes
}

void loop() {
 delay(100);
}

void I2C_Action(int nBytes)
{
	  byte I2C_Data = Wire.read();
	  
	  CA2 = (I2C_Data & 0b110000) >> 4;
	  CA1 = (I2C_Data & 0b001100) >> 2;
	  CA0 = (I2C_Data & 0b000011);
	  
	  //Serial.print("I2C Data Packet: "); //For debuggin purposes
	  //Serial.println(I2C_Data, BIN);
	  
	  
	  //Serial.print("CA2: ");
	  //Serial.println(CA2);
	  //Serial.print("CA1: ");
	  //Serial.println(CA1);
	  //Serial.print("CA0: ");
	  //Serial.println(CA0);
	  
	  //Serial.print("CA0 Binary: ");
	  //Serial.println(CA0, BIN);
	  
	  
	switch (CA2) {
		case 0:
			pinMode(CA2_Pin, OUTPUT);
			digitalWrite(CA2_Pin, LOW);
			//Serial.print("CA2: ");
			//Serial.println("LOW");
			break;
		case 2:
			pinMode(CA2_Pin, INPUT);
			//Serial.print("CA2: ");
			//Serial.println("FLOAT");
			break;
		case 3:
			pinMode(CA2_Pin, OUTPUT);
			digitalWrite(CA2_Pin, HIGH);
			//Serial.print("CA2: ");
			//Serial.println("HIGH");
			break;
		default:
			//Serial.print("CA2: ");
			//Serial.println("Default Case");
			break;
	}
	  
	switch (CA1) {
		case 0:
			pinMode(CA1_Pin, OUTPUT);
			digitalWrite(CA1_Pin, LOW);
			//Serial.print("CA1: ");
			//Serial.println("LOW");
			break;
		case 2:
			pinMode(CA1_Pin, INPUT);
			//Serial.print("CA1: ");
			//Serial.println("FLOAT");
			break;
		case 3:
			pinMode(CA1_Pin, OUTPUT);
			digitalWrite(CA1_Pin, HIGH);
			//Serial.print("CA1: ");
			//Serial.println("HIGH");
			
			break;
		default:
			//Serial.print("CA1: ");
			//Serial.println("Default Case");
			break;
		
		}  

	switch (CA0) {
		case 0:
			pinMode(CA0_Pin, OUTPUT);
			digitalWrite(CA0_Pin, LOW);
			//Serial.print("CA0: ");
			//Serial.println("LOW");
			break;
		case 2:
			pinMode(CA0_Pin, INPUT);
			//Serial.print("CA0: ");
			//Serial.println("FLOAT");
			break;
		case 3:
			pinMode(CA0_Pin, OUTPUT);
			digitalWrite(CA0_Pin, HIGH);
			//Serial.print("CA0: ");
			//Serial.println("HIGH");
			
			break;
		default:
			//Serial.print("CA0: ");
			//Serial.println("Default Case");
			break;
		
		} 	
	  

	  
	  while(Wire.available()) //Get rest of data to clear the read buffer. We don't care about the rest of the data
	  {
		Wire.read();
	  }
	  return;
}
