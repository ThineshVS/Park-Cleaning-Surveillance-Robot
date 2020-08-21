
#include "ESP8266WiFi.h"
#include <SoftwareSerial.h>
WiFiClient client;
WiFiServerserver(80);
SoftwareSerials(3,1);
const char* ssid = "THINESH"; 
const char* password = "12345678"; 
String data ="";
int  dataIn;
int leftMotorForward = 0;  //D3 
int rightMotorForward = 2; //D4
int leftMotorBackward = 13;  //D7 
int rightMotorBackward = 15; //D8
int vaccum = 5;  //D1
int ENA =14; //D5
int ENB =12; //D6
int speedCar = 1028;         

void setup()
{
Serial.begin(115200);
//WiFi.begin(ssid, password);
server.begin();
s.begin(115200);
pinMode(vaccum, OUTPUT); 
pinMode(leftMotorForward, OUTPUT);
pinMode(rightMotorForward, OUTPUT); 
pinMode(leftMotorBackward, OUTPUT);  
pinMode(rightMotorBackward, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
}

void loop()
{ 
client = server.available();
if (!client) return; 
data = checkClient ();
Serial.println(data);
dataIn = data.toInt();
s.write(dataIn);
if (data == "forward") MotorForward();
else if (data == "backward") MotorBackward();
else if (data == "left") TurnLeft();
else if (data == "right") TurnRight();
else if (data == "stop") MotorStop();
else if (data == "ON") ON();
else if (data == "OFF") OFF();
else if (data == "0") speedCar = 200;
else if (data == "1") speedCar = 300;
else if (data == "2") speedCar = 400;
else if (data == "3") speedCar = 500;
else if (data == "4") speedCar = 600;
else if (data == "5") speedCar = 700;
else if (data == "6") speedCar = 800;
else if (data == "7") speedCar = 900;
else if (data == "8") speedCar = 1000;
else if (data == "9") speedCar = 1028;


}  




void MotorForward(void)   
{

digitalWrite(leftMotorForward,HIGH);
digitalWrite(rightMotorForward,HIGH);
analogWrite(ENA, speedCar);
digitalWrite(leftMotorBackward,LOW);
digitalWrite(rightMotorBackward,LOW);
analogWrite(ENB, speedCar);
}

void MotorBackward(void)   
{

digitalWrite(leftMotorBackward,HIGH);
digitalWrite(rightMotorBackward,HIGH);
analogWrite(ENA, speedCar);
digitalWrite(leftMotorForward,LOW);
digitalWrite(rightMotorForward,LOW);
analogWrite(ENB, speedCar);
}


void TurnLeft(void)   
{

digitalWrite(leftMotorForward,LOW);
digitalWrite(rightMotorForward,HIGH);
analogWrite(ENA, speedCar);
digitalWrite(rightMotorBackward,LOW);
digitalWrite(leftMotorBackward,HIGH);
analogWrite(ENB, speedCar);  
}


void TurnRight(void)   
{

digitalWrite(leftMotorForward,HIGH);
digitalWrite(rightMotorForward,LOW);

analogWrite(ENA, speedCar);
digitalWrite(rightMotorBackward,HIGH);
digitalWrite(leftMotorBackward,LOW);
analogWrite(ENB, speedCar);
}


void MotorStop(void)   
{

digitalWrite(leftMotorForward,LOW);
digitalWrite(leftMotorBackward,LOW);
digitalWrite(rightMotorForward,LOW);
digitalWrite(rightMotorBackward,LOW);
}
void ON()
{
digitalWrite(vaccum,HIGH);        
}

void OFF()
{
digitalWrite(vaccum,LOW);        
}

String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
request.remove(0, 5);
request.remove(request.length()-9,9);
  return request;
}
