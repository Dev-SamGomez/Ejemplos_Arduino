#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;


int angulo1 = 90;
int angulo2 = 0;
int angulo3 = 180;
int angulo4 = 90;
int angulo5 = 90;
int suma = 5;



void setup() {

Serial.begin(9600);

                          /////////////////////////////SALIDAS DEL ARDUINO///////////////////////

servo1.attach(2);   /////////////SERVO BASE 1///////////////////
servo2.attach(3);   /////////////SERVO BASE 2//////////////////
servo3.attach(4);   ////////////SERVO EXTREMIDAD//////////////
servo4.attach(5);   ////////////SERVO GRIPPER O PINZA///////////
servo5.attach(6);   ////////////SERVO MUÑECA////////////////////

}

void loop() {

servo1.write(90);
servo2.write(0);
servo3.write(180);
servo4.write(90);
servo5.write(90);
delay(2000);
Bluetooth();

}



void Bluetooth(){

while(Serial.available()>0){

int option=Serial.read();


if(option==97){
BaseIn();
}
if(option==98){
BaseDec();
}
if(option==99){
BrazoIn();
}
if(option==100){
BrazoDec();
}
if(option==101){
Brazo2In();
}
if(option==102){
Brazo2Dec();
}
if(option==105){
MuneIn();
}
if(option==106){
MuneDec();
}
if(option==103){
PinzaIn();
}
if(option==104){
PinzaDec();
}
}


Bluetooth();
}


void BaseIn(){
angulo1+=10;
servo1.write(angulo1);
Bluetooth();
}

void BaseDec(){
angulo1-=10;
servo1.write(angulo1);
Bluetooth();
}

void BrazoIn(){
angulo2+=10;
servo2.write(angulo2);
Bluetooth();
}

void BrazoDec(){
angulo2-=10;
servo2.write(angulo2);
Bluetooth();
}

void Brazo2In(){
angulo3+=10;
servo3.write(angulo3);
Bluetooth();
}

void Brazo2Dec(){
angulo3-=10;
servo3.write(angulo3);
Bluetooth();
}

void MuneIn(){
angulo4+=10;
servo4.write(angulo4);
Bluetooth();
}

void MuneDec(){
angulo4-=10;
servo4.write(angulo4);
Bluetooth();
}

void PinzaIn(){
angulo5+=10;
servo5.write(angulo5);
Bluetooth();
}

void PinzaDec(){
angulo5-=10;
servo5.write(angulo5);
Bluetooth();
}

void rutina(){

for(angulo1  = 90; angulo1  <= 150; angulo1  += 1)
     {
          servo1.write(angulo1);
          delay(10);

     }
delay(1000);
          for(angulo2  = 0; angulo2  <= 30; angulo2  += 1)
          {
          servo2.write(angulo2);
          delay(10);
          }
delay(1000);

          for(angulo5  = 90; angulo5  <= 170; angulo5  += 1)
          {
               servo5.write(angulo5);
               delay(10);
          }
delay(1000);
               for(angulo3  = 180; angulo3  >= 130; angulo3  -= 1)
               {
               servo3.write(angulo3);
               delay(5);
               }
delay(1000);
for(angulo4  = 90; angulo4  <= 180; angulo4  += 1)
{
          servo4.write(angulo4);
          delay(5);
}
delay(1000);
rutina();
}
