#include <Servo.h>
Servo servo;
int pos=0;

void setup() {
  servo.attach(3);
  Serial.begin(9600);
}

void loop() {
  for(pos=0;pos <=180; pos+=1){
  servo.write(pos);
  delay(15);
  Serial.println(pos);
  }
  delay(2000);
  for(pos=180; pos>=0 ;pos-=1){
  servo.write(pos);
   delay(15);
   Serial.println(pos);
  }
  delay(2000);
}
