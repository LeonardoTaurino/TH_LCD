#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
// general var
int tempo=500;
//var lcd ---------------------
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
// var sensor ---------------
int sensorP=2;
DHT HT(sensorP,Type);
float temp;
float hum;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //Debugging  
// lcd var
lcd.begin(16,2);
// sensor var
HT.begin();
delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.clear();
hum=HT.readHumidity();
temp=HT.readTemperature();
lcd.setCursor(0,0);
lcd.print("T = ");
lcd.print(temp);
lcd.print(" C");
lcd.setCursor(0,1);
lcd.print("U = ");
lcd.print(hum);
lcd.print(" %");
delay(tempo);



}
