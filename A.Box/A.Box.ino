#include<Servo.h>

Servo servo1;
Servo servo2;

int pos1=0;
int buton = 2;
int sescal = 4;
int butondurumu;
int say=0;

void setup() {
 servo1.attach(9);
 servo2.attach(10);
 servo1.write(0);
 servo2.write(80);
 say=0;
 pinMode(buton, INPUT_PULLUP); //Sadece inputta saçmaladığı için pullup
 pinMode(sescal, OUTPUT); // Ses çalma modülüne gidecek pini çıkış olarak belirledik.
 digitalWrite(sescal, LOW); // İlk aşamada çalmasın diye ses modülüne 0 yolladık. 
}

void loop() {
  butondurumu = digitalRead(buton); //butona bak
  pos1=servo1.read(); //servo1 in pozisyonuna bak
    if(butondurumu == LOW){
      servo2.write(50);
      
        for(pos1; pos1 <= 150; pos1++)  
        {                                 
          servo1.write(pos1);              
          delay(2);                       
        }
       say++;
       // Gerekirse buraya biraz gecikme ekleyeceğiz !!!
       if(say==30){
         say=0;
         servo1.write(150);
         pos1=80;
         servo1.write(pos1);
         
         // Dönüş fake başlangıç
          for(pos1; pos1>=20; pos1--){
            servo1.write(pos1);
            delay(25);
            }
          servo1.write(150);
          pos1=80;
          servo1.write(pos1);
          digitalWrite(sescal, HIGH);
         digitalWrite(sescal, LOW);
         delay(5000);
          for(pos1; pos1>=20; pos1--){
            servo1.write(pos1);
            delay(25);
            }
           pos1=85;
           servo1.write(pos1);
           delay(1000);
           
         // Dönüş fake bitiş       
       say=0;  
     }   
    }else{ 
        for(pos1; pos1 > 0; pos1--)  
        { 
          servo1.write(pos1);
          butondurumu = digitalRead(buton); //Geriye dönerken her drc de butonu kontrol et 
          if(butondurumu==LOW){ //kapattıysa hemen aç
            servo2.write(50);
            servo1.write(150);
            pos1=150;
          }
                          
        } 
        servo2.write(80);
    }
}
