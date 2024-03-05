
//C++

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 11, 10, 9, 8, 7);
 
int temp=A5;
int luz=A4;
int Pir=A3;
int Umidade=A2;
int Moviment;
int Umidd;
//Ard_2
int S_1=6;
int S_2=5;
int S_3=3;
//Relogio_bot
int hrs=00;
int min=00;
int seg=04;
int flag=1; //PM
int hs=0;
int ms=0;
int ahr1;
int button1;
int button2;
// Tempo Real
static uint32_t tempo_corrido, now = 0;
//Variaveis
float luzv;
float moli;
float mobi;
float Movimento;


void setup()
{
//Ini_seri
Serial.begin(9600);
lcd.begin(16,2);
//Declaração
pinMode(A5,INPUT);
pinMode(A4,INPUT);
pinMode(A3,INPUT);
pinMode(A2,INPUT);
pinMode(7,OUTPUT);
pinMode(6,INPUT);
pinMode(A3,INPUT);
pinMode(hs,INPUT); 
pinMode(ms,INPUT);
now=millis(); 
//Comprimentações
lcd.setCursor(6,0);
lcd.print("Ola!");
lcd.setCursor(4,1);
lcd.print("Bom dia!");
delay(4000);
lcd.clear();
}

void loop()
{
lcd.clear();
pinMode(4, LOW);
makeTimer();
//Luz
luzv=analogRead(luz);
//Temperatura
moli=analogRead(temp);
//Calculo_Temp
moli=moli*5;
moli/=1024;
mobi=(moli-0.5)*100;
//Movimento
Movimento=analogRead(Pir);
//Umidade
Umidd=analogRead(Umidade);
//Registro
Serial.println("Movimento");
Serial.println(Movimento);
Serial.println("luz");
Serial.println(luzv);
Serial.println("temperatura");
Serial.println(mobi);
Serial.println("Umidade");
Serial.println(Umidd);
//lcd_info
lcd.setCursor(0,0);
lcd.print("C:");
lcd.setCursor(0,1);
lcd.print("Luz:");
lcd.setCursor(2,0);
registro_lcd();
//Condição_movimento
  if (Movimento>1) {
analogWrite(5,256);
pinMode(4 ,HIGH);
  }
//Condição_temp
  if (mobi>38) {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temperatura alta");
lcd.setCursor(0,1);
lcd.print("Extrema!");
analogWrite(6,128);
delay(1000);
makeTimer();
lcd.clear();
  }
  if (mobi<0) {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temp baixa");
lcd.setCursor(0,1);
lcd.print("Extrema!");
analogWrite(6,255);
delay(1000);
makeTimer();
lcd.clear();
  }
//relogio
Re_tmp_M;
lcd.setCursor(8,0);
  
if(hrs<10)lcd.print("0");// sempre 2 dígitos
lcd.print(hs);
lcd.print(":");
  
if(min<10)lcd.print("0");
lcd.print(ms);
lcd.print(":");
  
if(seg<10)lcd.print("0");
lcd.print(seg);

if(flag==0) lcd.print(" AM");
  
if(flag==1) lcd.print(" PM");

for (int i=0;i<5;i++) {
  while (now - tempo_corrido < 200) {
now = millis();
  }

tempo_corrido = now;
  
button1=digitalRead(hs);
button2=digitalRead(ms);

 } 
  }
void setTimer() {
 
if(!button1){
hrs=hrs+1;
makeTimer();
  }

 if(!button2){
seg=0;
ms=ms+1;
makeTimer();
  }
}
//CALCULO_HOR
void makeTimer() {
seg=seg+1;
Registro_serial();
if(seg==60){
seg=0;
ms=ms+1;
}
if(ms==60)
{
ms=0;
hrs=hrs+1;
}
if(hrs==13) {
hrs=1;
flag=flag+1;
if(flag==2)flag=0;
analogWrite(5,255);
pinMode(4, HIGH);
 }
}
 void registro_lcd() {
lcd.setCursor(2,0);
lcd.print(mobi);
  
lcd.setCursor(8,0); 
  
 if (luzv>950) {
lcd.setCursor(5,1);
lcd.print("Desligada");
delay(1500);
makeTimer();
  }
  else if (luzv<950) {
lcd.setCursor(5,1);
lcd.print("Ligada");
delay(1500);
makeTimer();
  }
 }
  void Re_tmp_M() {
  if (Movimento>100) {
analogWrite(3,256);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Movimento");
lcd.setCursor(0,1);
lcd.print("Dedectado!");
delay(1500);
makeTimer();
Serial.println("Movimento");
Registro_serial();
    }
  }
    void Registro_serial() {
Serial.println(mobi+String("   Horario:")+String(hrs)+String(":")+String(ms)+String(":")+String(seg));
     if (Movimento>100) {
Serial.println("Razao:Movimento");
     }
     if (mobi>38) {
Serial.println("Razao:Temperatura Alta");
Serial.println(mobi+String("   Horario:")+String(hrs)+String(":")+String(ms)+String(":")+String(seg));
     }
     if (mobi<0) {
Serial.println("Razao:Temperatura Baixa");
Serial.println(mobi+String("   Horario:")+String(hrs)+String(":")+String(ms)+String(":")+String(seg));
     }
  }
