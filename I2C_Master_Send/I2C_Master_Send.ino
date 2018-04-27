#define I2C_Low 0b00000000 //00 denotes to set the output pin to low
#define I2C_High 0b00000011 //11 denotes to set the output pin to high
#define I2C_Float 0b00000010 //10 denotes to set the pin to and input, causing it to be a floating voltage


byte CA2 = I2C_High; //Set the CA2 bit address here (Address 100 is reserved for the ATMega IC)
byte CA1 = I2C_Low;
byte CA0 = I2C_Float;

byte I2C_Data = 0; //This is the data packet to send to the I2C slave.
byte temp_Data = 0;

//byte aVar = 0b10100101;  //decimal 10 in msb and decimal 5 in lsb
void setup() 
{
  //Serial.begin(9600);
  I2C_Data = (I2C_Data | CA2) << 2;
  I2C_Data = (I2C_Data | CA1) << 2;
  I2C_Data = (I2C_Data | CA0);
  
  Wire.begin(); // join i2c bus
  
  Wire.beginTransmission(100); // transmit to device #100 (0x64)
                              // device address is specified in datasheet
  Wire.write(I2C_Data);       // sends I2C_Data byte  
  Wire.endTransmission();     // stop transmitting

  
  //int msb = (aVar & 0b11110000) >> 4;  //get the first 4 bits of the byte and shift them right 4 places
  //int lsb = aVar & 0b00001111;         //get the last 4 bits of the byte
  //Serial.println(I2C_Data);
  //Serial.println(CA2);
}

void loop() 
{

}

