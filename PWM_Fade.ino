/*
 Fade

 This example shows how to fade an LED on pin 4
 using the PWM librarie and a pot in analog pin A0.

 If you want to change the pin you're using, only
 change pin number in PWM instance parameter. 
 You can use any digital pin to drive this class.

 This example code is in the public domain.
 */
 
#include <PWM.h>      

int led = 4;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
long retard =100;      // this small retard is adequate for a led 
                       // but not for a motor or another rele driven item.
                       // In these cases use a value over 2000 

PWM pwm(led);          // PWM instance in digital pin 'led'

void setup() {
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
}
