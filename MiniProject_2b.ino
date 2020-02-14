#include <analogWrite.h>
//button connected to pin 13
const int fanPin = 13;
//// button connected to pin 21
const int buttonPin = 21;
// State of the button
byte current_button = LOW;
// Previous state of the button
byte old_button = LOW;

//button start time
unsigned long button_start;
//button end time
unsigned long button_end;
//time between button presses
unsigned long duration;

//string of dots and dashes
String s= "";
//button press number
int num=0;

//Morse Code Digit Series
String one="dotdashdashdashdash";
String two="dotdotdashdashdash";
String three= "dotdotdotdashdash";
String four= "dotdotdotdotdash";
String five= "dotdotdotdotdot";
String six= "dashdotdotdotdot";
String seven="dashdashdotdotdot";
String eight="dashdashdashdotdot";
String nine= "dashdashdashdashdot";
String zero= "dashdashdashdashdash";

void setup() {
// initialize the button pin as an input:
pinMode(buttonPin, INPUT);
//initialize the fan pin as an output
pinMode(fanPin, OUTPUT);
//initialize the serial monitor 
Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop(){
  current_button= digitalRead(buttonPin);
  while (current_button == HIGH && old_button == LOW){
    button_start = millis();
    old_button = HIGH;
    //for debouncing
    delay(200);
    
    }
  while (current_button == LOW && old_button == HIGH){
    button_end = millis();
    duration = button_end-button_start;
    old_button = LOW;

    //if duration is equal to a dot
    if (duration > 0 && duration <=300){
      s += "dot";
      num +=1;
      delay(100);

      //if duration is equal to a dash
    } else if (duration > 300){ 
      s+= "dash";
      num +=1;
      delay(100);
      }

     

 
    }

//while number of presses is equal to 5, find the corresponding digit
//,print the morse code digit, and set the fan to the correct speed
// (11% increase per digit and zero is off)
   while (num == 5){
     if(s.equals(one)){
       Serial.println(1);
       analogWrite(fanPin, 28);
       
    
    }
    
    if(s.equals(two)){
       Serial.println(2);
       analogWrite(fanPin, 56);
      
     
    }

    if(s.equals(three)){
       Serial.println(3);
       analogWrite(fanPin, 84); 

          
    }

    if(s.equals(four)){
       Serial.println(4);
       analogWrite(fanPin, 112); 

       
    }

    if(s.equals(five)){
       Serial.println(5);
       analogWrite(fanPin, 140); 
      
    }

    if(s.equals(six)){
       Serial.println(6);
       analogWrite(fanPin, 168); 

    }

    if(s.equals(seven)){
       Serial.println(7);
       analogWrite(fanPin, 196); 

    }


    if(s.equals(eight)){
       Serial.println(8);
       analogWrite(fanPin, 224); 

    }

    if(s.equals(nine)){
       Serial.println(9);
       analogWrite(fanPin, 252); 

    }

    if(s.equals(zero)){
       Serial.println(0);
       analogWrite(fanPin, 0); 
       delay(1000);

    }

       s= "";
       num=0;
    
    }

    


    
    
    




  

}
