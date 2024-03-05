
#include <Adafruit_LEDBackpack.h>


int Entr_1=A5;
int Entr_2=A4;
int Entr_3=A3;
int Umi_b=A2;
float val_1;
float val_2;
float val_3;
float Umi_l;
  
void setup()
{
Serial.begin(9600);
  
pinMode(A5,INPUT);
pinMode(A4,INPUT);
pinMode(A3,INPUT);
pinMode(A2,INPUT); 
}

void loop()
{
//Leitura
val_1=analogRead(Entr_1);
val_2=analogRead(Entr_2);
val_3=analogRead(Entr_3);
Umi_l=analogRead(Umi_b);
//Registro
Serial.println("Valor_1");
Serial.println(val_1);
Serial.println("Valor_2");
Serial.println(val_2);
Serial.println("Valor_3");
Serial.println(val_3);
Serial.println("Umidade");
Serial.println(Umi_l);
  
  if (val_1>0) {
pinMode(2, HIGH);
  }
  if (val_2>0) {
analogWrite(3, 256);
  }
delay(500);
}
