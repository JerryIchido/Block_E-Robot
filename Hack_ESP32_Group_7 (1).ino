#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
char readIn;

 void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  SerialBT.begin("ESP32_7");
  while(!SerialBT.available()){
    ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(SerialBT.available())
     {
      readIn = char(SerialBT.read());
      Serial1.println(readIn);
     }
   
}
