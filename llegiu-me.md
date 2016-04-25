#PWM

La Modulació d'amplada de pols o PWM, és una tècnica per obtenir resultats anàlegs amb mitjans digitals. El control digital s'utilitza per crear una ona quadrada, un senyal de commutació entre encès i apagat. Aquest patró d'encesa i apagada pot simular tensions entre el voltatge complet(5 volts) i la desactivació (0 volts) canviant el porcentatge de temps que el senyal està ON en comparació amb el temps que OFF. La durada del "temps" es diu 'ample de pols'. Per aconseguir variar els valors analògics, s'ha de canviar, o modular, aquest ample de pols. Si repeteix aquest patró d'encesa i apagada prou ràpid, amb un LED per exemple, el resultat és com si el senyal fos una tensió constant entre 0 i 5V controlant la brillantor del LED.

En el següent gràfic es pot veure com funciona aquesta tècnica. La durada del període de temps és la inversa de la freqüència PWM. En altres paraules, si s'utilitza un període de temps de 2 mil·lisegons, tindrem una freqüència PWM a aproximadament 500 Hz, les línies verticals mesurarien 2 mil·lisegons cada una. Una crida a setDutyCycle() és fa en una escala de 0 a 100, de manera que un setDuty(30) vol dir que la sortida és el 30% del voltatge total.

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
 

Arduino incorpora en el seu IDE una funció PWM que s'utilitza per al mateix propòsit, de la següent manera: 
     analogWrite (pin, valor);
on pin és un pin digital que permet PWM (en l'Arduino Uno els pins digitals 3, 5, 6, 9, 10 i 11) i el valor és un enter entre 0 i 255.
La funció que presentem pot operar en qualsevol dels pins digitals (1-13) i permet la variació de la base de temps de funcionament d'una manera molt simple, enviant el valor de temps mitjançant la funció setRetard(temps).

##Ús

En primer lloc instal·lem aquesta biblioteca a les biblioteques carpeta Arduino IDE, arrossegant la carpeta PWM dins de la carpeta 'biblioteques' o o com en les següents instruccions:
      https://www.arduino.cc/en/Guide/Libraries

Al començament del programa inclouen la biblioteca PWM:
      #include <PWM.h>
després declarem una instancia de classe amb el número de pin on volem aplicar la regulació:
      Pwm_1 PWM (8);
A la funció setup() initialitzem la instancia creada assignant un percentatge de cicle de treball (duty cycle) de 0 a 100%:
      pwm_1.setDuty(percentatge);
i un temp de retard en millisegons per establir la freqüencia del cicle de treball:
      pwm_1.setRetard(20);
a continuació, a la funció loop(), cridem la funció handler() que farà funcionar la classe:
      pwm_1.handler();

Si volem fer servir la funció en un altre pin digital, repetim aquests passos amb una nova instancia de PWM:
      PWM pwm_2;

Si necessitem coneixer el valor actual de la variable counter el podem obtenir mitjançant la funció getCounter():
      pwm_1.getCounter();
	  
##Exemples

PWM_Fade.ino
Exemple de regulació d'un LED amb un potenciometre, semblant a "Fade.ino" en Examples/01.Basics/Fade in Arduino IDE

PWM_Signal_Plotter.ino
Aquest exemple mostra tots els senyals del PWM (comptador, cicle de treball i Cicle de encesa/apagada) en un programa de representació gràfica de senyals sèrie, com  StampPlot Pro, Maker Plot o qualsevol programa similar

## Credits

Aquesta llibreria es fruit d'un treball de l'assignatura de Programació Industrial, al curs de 1er any  de AIRI, a l'IES Jaume Huguet de Valls, i esta basada en les explicacions i suggerències del professor, Dani Flores.

##Contribucions

Si descobreixes un bug o vols proposar qualsevol canvi o ampliació, si us plau enviem un correu electrònic a arduinoxino@gmail.com 

#Llicència

Aquesta llibrería constitueix un programari lliure; vostè pot redistribuir-lo i / o
modificar-lo sota els termes de la GNU Lesser General Public
License publicada per la Fundació per al Programari Lliure; sigui laversió 2.1 de la llicència, o qualsevol versió posterior.

Aquesta llibrería es distribueix amb l'esperança que sigui útil,
però sense cap garantia; ni tan sols la garantia implícita de
COMERCIALITZACIÓ o ADEQUACIÓ PER A PROPÒSITS DETERMINATS. 
Consulteu la GNU Lesser General Public License per a més detalls.

Haurieu de rebre una còpia de la GNU Lesser General Public
License juntament amb aquesta llibrería; si no, escriviu a la Free Software
Foundation, Inc., 51 Franklin St, Cinquè Pis, Boston, MA 02110-1301 EUA
