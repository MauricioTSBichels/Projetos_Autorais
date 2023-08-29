//c++

#include <Adafruit_LiquidCrystal.h>

int trig=6; 
int echo=5;
Adafruit_LiquidCrystal lcd(0);

//variaveis
int pingTime;
float targetDistanceCm; 


void setup() {
pinMode(13, OUTPUT);
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);  
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}
  
void loop() {
  
digitalWrite(9,LOW);  
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
  
if (targetDistanceCm > 40) {
    lcd.print(" Longe ");
    digitalWrite(13, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    delay(300);
    digitalWrite(8, LOW);
} 
else if (targetDistanceCm < 40) {
    lcd.print(" Perto ");
   digitalWrite(13, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(300); 
    digitalWrite(9, LOW);
}

delay(1000);

}  
