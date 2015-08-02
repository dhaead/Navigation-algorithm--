#include <SD.h>
#include <SPI.h>
//SPI Settings
//int MOSI=51;//DI pin 51 2560
//int MISO=50; //D0 pin 50 mega 2560
//int SCLK=52;    //sd card clock goes to pin 52 set by default
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
String dataString = "writing data to log2";
File dataFile = SD.open("log2.txt", FILE_WRITE);
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
