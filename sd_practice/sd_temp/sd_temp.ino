#include <SD.h>
#include <SPI.h>
//This code takes temperature readings from a lm35 temperature sensor
//and display the reading serially to the serial monitor. In addition
//the temperature in farenheit is written to sd card and can be read with
//read_log
int t=0;
int sensor=A1; // sets A1 as the sensor input
float temp;
float tempc;
float tempf;
//SPI Settings
//int MOSI=51;//DI pin 51 2560
//int MISO=50; //D0 pin 50 mega 2560
//int SCLK=52;    //sd card clock goes to pin 52 set by default
int CS_pin=53;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Serial.println("Initializing Card");
pinMode(CS_pin, OUTPUT);
pinMode(sensor,INPUT);
  
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
String dataString = "Temperature F";
 delay(2000); // calls a 2 second delay
  t=t+2;       // increments the time by 2 every two seconds
  temp=analogRead(sensor); // reads the LM35 output
  tempc=(temp*5)/10;       // converts the digital value into temperature degree C
  tempf=(tempc*1.8)+32;    // converts degree C to degree F
  Serial.println("...............");
  Serial.println("Temperature logger");
  Serial.print("Time in sec = ");  // prints the time on serial monitor window
  Serial.println(t);
  Serial.print("Temperature in deg C = "); // prints the temperature in degreeC
  Serial.println(tempc);
  Serial.print("Temperature in deg F = "); // prints the temperature in degreeF
  Serial.println(tempf);

File dataFile = SD.open("temps.txt", FILE_WRITE);
if(dataFile)
  {
  dataFile.println(dataString);
  dataFile.println(tempf);
  dataFile.close();
  }
  else
  {
    Serial.println("couldn't access file");
  }

//Only one file can be open at a time
delay(3000);
}
