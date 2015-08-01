void setup() {
  // put your setup code here, to run once:

pinMode(pow_pin, OUTPUT);
digitalWrite(pow_pin,HIGH);
//check if card ready
if(!SD.begin(CS_pin))



}

void loop() {
  // put your main code here, to run repeatedly:
String dataString = "Hello"


//Only one file can be open at a time
delay(5000)
}
