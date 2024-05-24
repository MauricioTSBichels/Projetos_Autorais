// C++ code
//
const int mot_esq_1 = 13;
const int mot_drt_1 = 12;
const int rele_pcima = 11;
const int rele_pbaixo = 10;
const int gatilho_pin = 8;
const int ms_b = 5;
const int ms_m = 3;
// Botões
const int bt_1 = A5;
const int bt_2 = A4;
const int bt_3 = A3;
const int bt_4 = A2;
const int bt_5 = A1;
// Visor
const int s_1 = 9;
const int s_2 = 7;
const int s_3 = 6;
const int s_4 = 5;
const int s_5 = 4;
const int s_6 = 3;
const int s_7 = 2;

// Variáveis
int esq_1;
int drt_1;
int pcima;
int pbaixo;
int gatilho;
int muni = 0;

void setup() {
  Serial.begin(9600);
  // Configuração dos pinos
  pinMode(mot_esq_1, OUTPUT);
  pinMode(mot_drt_1, OUTPUT);
  pinMode(rele_pcima, OUTPUT);
  pinMode(rele_pbaixo, OUTPUT);
  pinMode(gatilho_pin, OUTPUT);
  pinMode(ms_b, OUTPUT);
  pinMode(ms_m, OUTPUT);

  pinMode(bt_1, INPUT);
  pinMode(bt_2, INPUT);
  pinMode(bt_3, INPUT);
  pinMode(bt_4, INPUT);
  pinMode(bt_5, INPUT);

  pinMode(s_1, OUTPUT);
  pinMode(s_2, OUTPUT);
  pinMode(s_3, OUTPUT);
  pinMode(s_4, OUTPUT);
  pinMode(s_5, OUTPUT);
  pinMode(s_6, OUTPUT);
  pinMode(s_7, OUTPUT);
}

void loop() {
  Serial.println("-------------------------------------------------------------------------");
  if (muni <= 0) {
    muni = 7;
  }
  
  // Botão esquerda_1
  Serial.println("esq_1:");
  esq_1 = analogRead(bt_1);
  if (esq_1 > 1013) {
    esq_1 = 1;
  }
  else {
    esq_1 = 2;
  }
  Serial.println(esq_1);
  digitalWrite(mot_esq_1, esq_1 < 2 ? HIGH : LOW);

  // Botão direita_1
  Serial.println("drt_1:");
  drt_1 = analogRead(bt_2);
  if (drt_1 > 1013) {
    drt_1 = 1;
  }
  else {
    drt_1 = 2;
  }
  Serial.println(drt_1);
  digitalWrite(mot_drt_1, drt_1 < 2 ? HIGH : LOW);

  // Rele pcima
  Serial.println("pcima:");
  pcima = analogRead(bt_3);
  if (pcima > 1013) {
    pcima = 1;
  }
  else {
    pcima = 2;
  }
  Serial.println(pcima);
  digitalWrite(rele_pcima, pcima < 2 ? HIGH : LOW);

  // Rele pbaixo
  Serial.println("pbaixo:");
  pbaixo = analogRead(bt_4);
  if (pbaixo > 1013) {
    pbaixo = 1;
  }
  else {
    pbaixo = 2;
  }
  Serial.println(pbaixo);
  digitalWrite(rele_pbaixo, pbaixo < 2 ? HIGH : LOW);

  // Gatilho
  Serial.println("gatilho:");
  gatilho = analogRead(bt_5);
  if (gatilho > 1013) {
    gatilho = 1;
  }
  else {
    gatilho = 2;
  }
  Serial.println(gatilho);
  if (gatilho < 2) {
    digitalWrite(gatilho_pin, HIGH);
    muni = muni - 1;
  }
  else {
    digitalWrite(gatilho_pin, LOW);
  }

  // Visor
  Serial.println("muni:");
  Serial.println(muni);
  if(muni==7){
   digitalWrite(s_1, LOW);
   digitalWrite(s_2, LOW);
   digitalWrite(s_3, HIGH);
   digitalWrite(s_4, HIGH);
   digitalWrite(s_5, LOW);
   digitalWrite(s_6, LOW);
   digitalWrite(s_7, HIGH);  
   }
  if(muni==6) {
   digitalWrite(s_1, HIGH);
   digitalWrite(s_2, HIGH);
   digitalWrite(s_3, HIGH);
   digitalWrite(s_4, LOW);
   digitalWrite(s_5, HIGH);
   digitalWrite(s_6, HIGH);
   digitalWrite(s_7, HIGH);  
  }
  if(muni==5) {
   digitalWrite(s_1, HIGH);
   digitalWrite(s_2, HIGH);
   digitalWrite(s_3, HIGH);
   digitalWrite(s_4, LOW);
   digitalWrite(s_5, LOW);
   digitalWrite(s_6, HIGH);
   digitalWrite(s_7, HIGH);   
  }
  if(muni==4) {
   digitalWrite(s_1, HIGH);
   digitalWrite(s_2, HIGH);
   digitalWrite(s_3, LOW);
   digitalWrite(s_4, HIGH);
   digitalWrite(s_5, LOW);
   digitalWrite(s_6, LOW);
   digitalWrite(s_7, HIGH);
  }
  if(muni==3) {
   digitalWrite(s_1, HIGH);
   digitalWrite(s_2, LOW);
   digitalWrite(s_3, HIGH);
   digitalWrite(s_4, HIGH);
   digitalWrite(s_5, LOW);
   digitalWrite(s_6, HIGH);
   digitalWrite(s_7, HIGH); 
  }
  if(muni==2) {
   digitalWrite(s_1, HIGH);
   digitalWrite(s_2, LOW);
   digitalWrite(s_3, HIGH);
   digitalWrite(s_4, HIGH);
   digitalWrite(s_5, HIGH);
   digitalWrite(s_6, HIGH);
   digitalWrite(s_7, LOW); 
   }
  if(muni==1) {
   digitalWrite(s_1, LOW);
   digitalWrite(s_2, LOW);
   digitalWrite(s_3, LOW);
   digitalWrite(s_4, HIGH);
   digitalWrite(s_5, LOW);
   digitalWrite(s_6, LOW);
   digitalWrite(s_7, HIGH); 
   }
}
