#include <SD.h>
#include <SPI.h>
//SPI Settings
//MOSI,MISO,SCLK set by default
int CS_pin=10;
int pow_pin=8;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Serial.println("Initializing Card");
pinMode(CS_pin, OUTPUT);
pinMode(pow_pin, OUTPUT);
digitalWrite(pow_pin,HIGH);
//check if card ready
if(!SD.begin(CS_pin))
  {
    Serial.println("Card Failed");
    return;
  }
  Serial.println("Card Ready");
}
void loop() 
{
  // put your main code here, to run repeatedly:
String dataString = "Hello";
File dataFile = SD.open("log.txt", FILE_WRITE);
if(dataFile)
  {
  dataFile.println(dataString);
  dataFile.close();
  }
  else
  {
    Serial.println("couldn't access file");
  }

//Only one file can be open at a time
delay(5000);
}
