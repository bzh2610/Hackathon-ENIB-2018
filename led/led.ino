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



void setDigit(int digit){
   for (int i = 0; i < 16; i++) {
    Tlc.set(i, 4095);
  }
  
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
  

void setup() {
  Tlc.init(0); // Initiates the TLC5940 and set all channels off
}
 
void loop() {
  Tlc.set(0,4095); //(Output Pin from 0 to 15,PWM Value from 0 to 4095)
  // Note: The previous function doesn't activates the output right away. The output will be activated when the Tlc.update() function will be executed!
  
  //Tlc.update();
  //delay(1000);

  //The Tlc.clear() function clears all the outputs, or sets the PWM value of all outputs to 0



  for(int i=0; i<10; i++){
  setDigit(i);
   Tlc.update();
    delay(1000);
  }

  // This for loop will active all 16 LEDs one by one
  
  /*for (int i = 0; i < 16; i++) {
    Tlc.set(i, 4095);
    Tlc.update();
    delay(200);
  //  Tlc.clear();
    Tlc.update();

  }*/
}
