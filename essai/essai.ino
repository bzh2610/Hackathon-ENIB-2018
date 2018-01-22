/*
 * Arduino and TLC5940 Tutorial - Simple Example
 * by Dejan Nedelkovski, www.HowToMechatronics.com

  __1__ 
 |     |
2|     6
 |__7__|
 |     |
3|     5
 |__4__|
 
 
 
 */




#include "Tlc5940.h" 

int periode=2000;// période entre chaque début d'impulsion en microsecondes
int pinServo=8; // variable pour le pin connecté à la commande du servo
int ledV=2;
int ledR=4;

//fonction setAngle pour envoyer les impulsions
void setAngle(int a){
  int duree=map(a,0,179,250,3000);// on transforme l'angle en microsecondes et on stocke dans la variable duree
  digitalWrite(pinServo,LOW);//on met le pin à l'état bas
  
  // la boucle qui suit est nécessaire 
  // pour laisser le temps au servo d'aller à sa position
  for (int t=0;t<300;t++){ 
    digitalWrite(pinServo,HIGH);// on envoie l'impulsion
    delayMicroseconds(duree); // pendant la bonne durée
    digitalWrite(pinServo,LOW); // on stoppe l'impulsion
    delayMicroseconds(periode-duree); // on attend le temps restant pour atteindre la période
  }
}




// La fonction setDigit permet de convertir un entier en affichage sur l'afficheur 7 segments
void setDigit(int digit){
  //On initialise toutes les leds
   for (int i = 0; i < 16; i++) {
    Tlc.set(i, 4095);
  }


  //On controle les leds à allumer.
  if(digit == 0){
    for(int i =0; i<7; i++){
    Tlc.set(i, 0);
    }
  }else   if(digit == 1){
    for(int i =2; i<4; i++){
    Tlc.set(i, 0);
    }
  }else   if(digit == 2){
        Tlc.set(1, 0);
        Tlc.set(6, 0);
        Tlc.set(7, 0);
         Tlc.set(3, 0);
          Tlc.set(4, 0);
  }else   if(digit ==3){
        Tlc.set(1, 0);
        Tlc.set(6, 0);
        Tlc.set(7, 0);
         Tlc.set(5, 0);
          Tlc.set(4, 0);
    }else   if(digit ==4){
        Tlc.set(2, 0);
        Tlc.set(6, 0);
        Tlc.set(7, 0);
         Tlc.set(5, 0);
    }else   if(digit ==5){
        Tlc.set(1, 0);
        Tlc.set(2, 0);
        Tlc.set(7, 0);
         Tlc.set(5, 0);
        Tlc.set(4, 0);
    }else   if(digit ==6){
        Tlc.set(1, 0);
        Tlc.set(2, 0);
        Tlc.set(3, 0);
         Tlc.set(5, 0);
        Tlc.set(4, 0);
          Tlc.set(7, 0);
    }else   if(digit ==7){
        Tlc.set(1, 0);
        Tlc.set(6, 0);
        Tlc.set(5, 0);
    }else   if(digit ==8){
        for(int i =0; i<9; i++){
          Tlc.set(i, 0);
          }
    }else   if(digit ==9){
        for(int i =0; i<9; i++){
          Tlc.set(i, 0);
          }
          Tlc.set(3, 4095);
    }
 

}
  
int i=1;


void setup() {
  Tlc.init(0); // Initiates the TLC5940 and set all channels off

  pinMode (7,INPUT);
  pinMode(ledV,OUTPUT);
  pinMode(ledR,OUTPUT);
  Serial.begin(9600);
  pinMode(pinServo,OUTPUT);// on prépare le pin en mode OUTPUT
  digitalWrite(pinServo,LOW); // on l'initialise à l'état bas
  digitalWrite(ledR,LOW);// on éteind la led Rouge
  digitalWrite(ledV,HIGH);// on allume la led Verte
  
  
}
 
void loop() {
   int M = digitalRead(7); //Mid sensor

  Tlc.set(0,4095); //(Output Pin from 0 to 15,PWM Value from 0 to 4095)

  // Note: The previous function doesn't activates the output right away. The output will be activated when the Tlc.update() function will be executed!


  


  //The Tlc.clear() function clears all the outputs, or sets the PWM value of all outputs to 0
      if(!M){
        if(i<=6){
         digitalWrite(ledR,LOW);// on éteind la led Rouge
         digitalWrite(ledV,HIGH);// on allume la led Verte
         
         setDigit(i);
         i+=1;
         Tlc.update();
         Serial.println("C'EST L HEURE DE L'APEROOOOO");
         setAngle(40);
         delay(1500); 
         setAngle(100);
         delay(1500); 
        }
     else{
        digitalWrite(ledV,LOW);// on éteind la led Verte
        digitalWrite(ledR,HIGH);// on allume la led Rouge
        
        //delay(15000);      
        }
      }
  
}
