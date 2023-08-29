//c++

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 10, 7, 4, 3, 2);  

//Entrada sensor
int trig=9; 
int echo=5;

//Variaveis
int pingTime;  
float targetDistanceCm; 


void setup() {
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}
  
void loop() {
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Distancia:");
  
digitalWrite(trig,HIGH);
delay(1);
digitalWrite(trig,LOW);
pingTime=pulseIn(echo,HIGH);
targetDistanceCm=pingTime/58.2;
Serial.println(targetDistanceCm);
  
lcd.setCursor(0,1);
lcd.print(targetDistanceCm+String("cm"));
delay(1000);
    
}
