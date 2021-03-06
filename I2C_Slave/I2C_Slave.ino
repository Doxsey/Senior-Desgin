#include <Wire.h>
#include <EEPROM.h>

#define CA2_Pin 2
#define CA1_Pin 3
#define CA0_Pin 4

byte CA2 = 0;
byte CA1 = 0;
byte CA0 = 0;

void I2C_Action(int);

void setup() {
  //Serial.end();
	//Serial.begin(9600); //For Debugging
	Init_EEPROM_Values(); //Read initial values from EEPROM and initialize the address pins
	Wire.begin(100);	// join i2c bus with a//ddress #100
	Wire.onReceive(I2C_Action);	//Setup routine for i2c data receive
}

void loop() { //Emtpy loop. Will enter I2C_Action when I2C data is received
 delay(100);
}

void I2C_Action(int nBytes){
	//Serial.println("I2C Action");
	int eeAddress = 0;
	byte I2C_Data = Wire.read();
	CA2 = (I2C_Data & 0b110000) >> 4;
	CA1 = (I2C_Data & 0b001100) >> 2;
	CA0 = (I2C_Data & 0b000011);
	
	EEPROM.update(eeAddress, I2C_Data); //Writes the address to EEPROM. Update will only change EEPROM if it's different
	
	addressChange(); //Calls the function to change output pins based on possible address change

	while(Wire.available()) //Get rest of data to clear the read buffer. We don't care about the rest of the data
		{
		Wire.read();
		}
	return;
}


void Init_EEPROM_Values(){ //Read initial values from EEPROM and initialize the address pins
	
	int eeAddress = 0;
	byte i2c_addr = 0;
	
	EEPROM.get(eeAddress, i2c_addr);
	i2c_addr = (byte) i2c_addr;
	
	CA2 = (i2c_addr & 0b110000) >> 4;
	CA1 = (i2c_addr & 0b001100) >> 2;
	CA0 = (i2c_addr & 0b000011);
	 
	addressChange(); //Calls the function to change output pins based on possible address change
	
}

void addressChange() //Function to house the case statement whenever an address change may have occured
{ 

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


		
}
