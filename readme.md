#PWM

Pulse Width Modulation, or PWM, is a technique for getting analog results with digital means. Digital control is used to create a square wave, a signal switched between on and off. This on-off pattern can simulate voltages in between full on (5 Volts) and off (0 Volts) by changing the portion of the time the signal spends on versus the time that the signal spends off. The duration of "on time" is called the pulse width. To get varying analog values, you change, or modulate, that pulse width. If you repeat this on-off pattern fast enough with a LED, for example, the result is as if the signal is a steady voltage between 0 and 5v controlling the brightness of the LED. 

In the graphic below you can see haw this technique works. The time period duration is the inverse of the PWM frequency. In other words, if we use a time period of 2 milliseconds, we will have a PWM frequency at about 500Hz, the green lines would measure 2 milliseconds each. A call to setDutyCycle() is on a scale of 0 - 100, so a setDuty(30)means that output is 30% of total output. 

    0% Duty Cycle -> setdutyCycle(0);

 5v |   Duty   |          |          |          |          |          |
    |<- Cycle->|          |          |          |          |          |
    |          |          |          |          |          |          |
 0v -------------------------------------------------------------------
 
    30% Duty Cycle -> setdutyCycle(30);
            
 5v +---+      +---+      +---+      +---+      +---+      +---+      +
    |   |      |   |      |   |      |   |      |   |      |   |      |
    |   |      |   |      |   |      |   |      |   |      |   |      |
 0v -   +------+   +------+   +------+   +------+   +------+   +------+
  
    60% Duty Cycle -> setdutyCycle(60);

 5v +------+   +------+   +------+   +------+   +------+   +------+   +
    |      |   |      |   |      |   |      |   |      |   |      |   |
    |      |   |      |   |      |   |      |   |      |   |      |   |
 0v -      +---+      +---+      +---+      +---+      +---+      +---+
  
    100% Duty Cycle -> setdutyCycle(100);
    
 5v +------------------------------------------------------------------
    |
    | 
 0v -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 
 Arduino incorporates in its IDE a PWM function used for the same purpose, as follows: analogWrite (pin, value), where pin is a digital pin that allows PWM (on the Arduino Uno digital pins 3, 5, 6 , 9, 10 and 11) and value is an integer between 0 and 255.
The function we discussed can operate in any of the digital pins (1-13) and allows varying the time base operating in a very simple way, sending the value of time by setRetard(time) function .

##Usage

In the first place we install this library in the libraries folder Arduino IDE, dragging the PWM folder inside the 'libraries' folder or or as in the following instructions:
      https://www.arduino.cc/en/Guide/Libraries

At the beginning of the program include the PWM library:
      #include <PWM.h>
then declare an instance of class with the pin number where you want to apply regulation:
      Pwm_1 PWM (8);
In the setup() function, initialize the instance created by assigning a percentage of duty cycle (0 to 100%):
      pwm_1.setDuty(percentage);
and a delay time in milliseconds to set the frequency of the work cycle:
      pwm_1.setRetard(20);
then, in the loop() function, call the handler() function that will run the class:
      pwm_1.handler();

If you want to use the function in another digital pin, repeat these steps with a new instance of PWM:
PWM pwm_2;

If you need to know the actual value of the counter variable, you can get it with the getCounter() function:
      pwm_1.getCounter();
	  
##Examples

PWM_Fade.ino
Example of regulation of a LED with a potenciometer, similar to "fade.ino" in Examples/01.Basics/Fade in Arduino IDE

PWM_Signal_Plotter.ino
This example shows all PWM signals in a graphic plotteras StampPlot Pro, Maker Plot or another similar software

## Credits

This library is the result of the Industrial programming course, during the 1st year of AIRIS studies, at IES Jaume  in Valls, and is based on the explanations and suggestions of the course Professor, Dani Flores.

##Contributing

If you discover a bug or would like to propose a new feature, please send me a mail to arduinoxino@gmail.com 

# License

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
