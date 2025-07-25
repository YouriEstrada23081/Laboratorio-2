//*************************************/
// Universidad del Valle de Guatemala
// BE30239 Electronica digital 2
// Youri Estrada 
// Laboratorio 2
// MCU: Esp32 dev kit 1.0
//************************************/

#include <Arduino.h>

#define LED1 33
#define LED2 25
#define LED3 26
#define LED4 27

#define bt1 2
#define bt2 17
#define bt3 18
int estado=0;
int contador=0;
unsigned long ts = 0;
unsigned long tr = 0;
const long d = 300; 
unsigned long e = 0;

bool us2= false;
bool us3=false;
bool er=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(bt1,INPUT);
  pinMode(bt2, INPUT_PULLDOWN);
  pinMode(bt3,INPUT_PULLUP);

  Serial.begin(115200);

}

void loop() {
    bool b2=digitalRead(bt2);
    bool b3=digitalRead(bt3);
    bool e1=digitalRead(bt1);
    if(e1==HIGH && er==false){
      if ((millis()-e)>d)
      {
        estado++;
        contador=0;
        e=millis();
      }
      if(estado==2){
        estado=0;
        contador=0;
    }}
      
  switch(estado){
    case 0:
      if (b2 == true && us2 == false) { 
        if ((millis() - ts) > d) { 
          contador++;
          ts = millis();
        }
      }
      us2=b2;
    
      if (b3 == true && us3 == false) { 
        if ((millis() - tr) > d) { 
          contador--;
          tr = millis();
        }
      }
      us3=b3;
      if (contador==-1){
        contador=4;
      }
      if (contador==5){
        contador=0;
      }
      switch (contador)
      {
      case 0:
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        break;
      case 1: 
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        break;
      case 2:
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        break;
      case 3: 
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, LOW);
        break;
      case 4: 
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, HIGH);
        break;
      }
      break;
    case 1:
           if (b2 == true && us2 == false) { 
        if ((millis() - ts) > d) { 
          contador++;
          ts = millis();
        }
      }
      us2=b2;
    
      if (b3 == true && us3 == false) { 
        if ((millis() - tr) > d) { 
          contador--;
          tr = millis();
        }
      }
      us3=b3;
      if (contador==-1){
        contador=15;
      }
      if (contador==16){
        contador=0;
      }
      
      switch (contador){
      case 0:
          digitalWrite(LED4, LOW);
          digitalWrite(LED3, LOW);
          digitalWrite(LED2, LOW);
          digitalWrite(LED1, LOW);
        break;
      case 1: 
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        break;
      case 2:
        digitalWrite(LED4, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, LOW);
        break;
      case 3: 
        digitalWrite(LED4, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, HIGH);
        break;
      case 4: 
        digitalWrite(LED4, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, LOW);
        break;
      case 5:
        digitalWrite(LED4, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, HIGH);
        break;
      case 6: 
        digitalWrite(LED4, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, LOW);
        break;
      case 7: 
        digitalWrite(LED4, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, HIGH);
        break;
      case 8:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, LOW);
        break;
      case 9:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, HIGH);
        break;
      case 10:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, LOW);
        break;
      case 11:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, HIGH);
        break;
      case 12:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, LOW);
        break;
      case 13:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, HIGH);
        break;
      case 14:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, LOW);
        break;
      case 15:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, HIGH);
        break;
      }
      break;         
    }

      
    
  } 


