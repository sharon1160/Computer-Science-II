const int sensor = 0 ;
const int ledrojo = 5 ;
const int ledAzul = 6 ;// Pin que lee la temperatura

long milivolts;
long temperatura;

void setup()
{    
  Serial.begin(9600);     
}

void loop()
   {    milivolts = (analogRead(sensor)* 5000L)/1023;
        milivolts= milivolts /10;

        Serial.print("temperatura: ") ;
        Serial.print(temperatura) ;
        Serial.println(" grados ");
        delay(200);
   }
