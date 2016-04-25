/*
 Fade

 This example shows all PWM signals in a graphic plotter
 as StampPlot Pro, Maker Plot or another similar software.

 When you change the Duty Cycle or the Frequency time,
 you will see the plotings signals in the program screen. 
 
 Adjust X axis to 160 to see all signals in full scale.
                            
         |<cycle>|       Duty
160+     +--+    +--+    +--+   + 
   |     |ON| OFF|  |    |  |   |
112+     |  +----+  +----+  +---+
   |  
 96|         /|      /|      /| <-- Counter
   |       /  |    /  |    /  |
 30|     /----|--/----|--/----| <-- Duty Cycle
  0|   /      |/      |/      |
  0|----------.-------.-------.
 This example code is in the public domain.
 */
 
#include <PWM.h>      

int led = 4;             // the PWM pin the LED is attached to
int brightness = 0;      // how bright the LED is
long retard =5000;        // this small retard is adequate for a led 
                         // but not for a motor or another rele driven item.
                         // In these cases use a value over 2000 
unsigned long tempActual;// Timer variables
unsigned long tempVell;
bool xflagShowPWM;

PWM pwm(led);          // PWM instance in digital pin 'led'

void setup() {
  Serial.begin(9600);   // Serial comm inicialization
  // declare pin `led' to be an output:
  pinMode(led, OUTPUT);
  // declare pin A0 to be an input (brightness level):
  pinMode(A0, INPUT);
  pwm.setRetard(retard); // initializes the delay
}

void loop() {
  // call handler function of PWM class every loop
  pwm.handler(); 
  // takes the value of the pot, map it and passes it to the control variable
  brightness=map(analogRead(A0),0,1023,0,100); 
  // set the brightness of pin 9
  pwm.setDuty(brightness);
  //if(xflagShowPWM){
   // xflagShowPWM = false;
    LlegirSerial();
  //}
}

void LlegirSerial(){
   Serial.print(110+digitalRead(led)*50);
   Serial.print(",");
   Serial.print(brightness);
   Serial.print(",");
   Serial.println(pwm.getCounter());
}

void Temporitzador() {
  tempActual = millis();
  if (tempActual - tempVell >= 100) {  // Timer to Write Serial signals each 100ms
    tempVell = tempActual;
    xflagShowPWM = true;
  }
}
