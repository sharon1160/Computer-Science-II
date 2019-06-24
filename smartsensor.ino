#include <LiquidCrystal.h>
#include <Servo.h>

//Puertos LCD -> RS E D4 D5 D6 D7 
LiquidCrystal lcd(8,9,10,11,12,13);
Servo servo1;
int red=4;
int green=7;
int blue=6;
int buzzer=5;
int ventilador=2;
int sensorTemperatura=0;
float temperaturaValor;
void setup(){
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ventilador,OUTPUT);
  servo1.attach(3);
}

void loop(){
  /*temperaturaValor=analogRead(sensorTemperatura);
  temperaturaValor=(5*(temperaturaValor)*100/1024);
  */
  temperaturaValor=34.0;
  Serial.println(temperaturaValor);
  lcd.setCursor(0,0);
  lcd.print("Temp= ");
  lcd.print(temperaturaValor);
  lcd.print(" c");
  delay(100);
  if(temperaturaValor > 35){
    tempCalor();
    buzzerCalor();
  } else if (temperaturaValor > 30){
    tempNormal();
    buzzerNormal();
  }
    else if(temperaturaValor < 30){
      tempFrio();
      buzzerFrio();
    }
}  
void tempCalor(){
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(ventilador,HIGH);
  servo1.write(150);
  lcd.setCursor(0, 1);
  lcd.print("Estado=Caliente");  
}
void buzzerCalor(){
  tone(5,1000, 200);
  delay(500);
  tone(5,1000, 200);
  delay(500);
}
void tempNormal(){
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(ventilador,LOW);
  servo1.write(90);
  lcd.setCursor(0, 1);
  lcd.print("Estado=Ambiente");
}
void buzzerNormal(){
  tone(5,200, 400);
  delay(1000);
  tone(5,200, 400);
  delay(1000);
}
void tempFrio(){
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  digitalWrite(ventilador,LOW);
  servo1.write(40);
  lcd.setCursor(0, 1);
  lcd.print("Estado=Frio");
}
void buzzerFrio(){
  tone(5,100, 600);
  delay(1000);
  tone(5,100, 600);
  delay(1000);
}
