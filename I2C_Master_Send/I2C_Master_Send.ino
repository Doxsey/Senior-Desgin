byte bit0 = B01;
byte bit1 = B10;
byte bit2 = B00;
byte I2C_Addr = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
bitWrite(I2C_Addr, 5, bitRead(bit0, 1));
bitWrite(I2C_Addr, 4, bitRead(bit0, 0));

bitWrite(I2C_Addr, 3, bitRead(bit1, 1));
bitWrite(I2C_Addr, 2, bitRead(bit1, 0));

bitWrite(I2C_Addr, 1, bitRead(bit2, 1));
bitWrite(I2C_Addr, 0, bitRead(bit2, 0));
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(bit0 | I2C_Addr);
//I2C_Addr = I2C_Addr << 2;
Serial.println(I2C_Addr);
while(1);
}
