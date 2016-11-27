#include "pitches.h"
/* Pin Definitions */
// LEDs: white LEDs are connected to 5, 6, A2, A3, A4
int ledPins[] = {5, 6, A2, A4, A3, 9, 10, 11};
int switchPin = 2;
int buttonPin = A5;
int vibePin = 3;
int buzzerP = 7;
int buzzerN = 12;
int lightSensorPin = A6;
int tempSensorPin = A1;

/* Global variables */
int light = 100;


void setup() {     
pinMode(7, OUTPUT);   
pinMode(12, OUTPUT);       
digitalWrite(9,LOW);

//STARTUP LED SEQUENCE
  for(int i=0; i<5; i++)      // This for loop will run 5 times
  {                           // blink the white LEDs (first 5 LEDs in ledPins array)
    pinMode(ledPins[i], OUTPUT);  // set pin as output
    digitalWrite(ledPins[i], HIGH); // turn LED on
    delay(250);                // wait for a quarter second
    digitalWrite(ledPins[i], LOW); // turn LED off
  }
  for(int i=5;i<8;i++)        // This for loop will run 3 times
  {                           // blink the RGB LEDs (last 3 LEDs in ledPins array)
    pinMode(ledPins[i], OUTPUT);    // set the pin as an output 
    digitalWrite(ledPins[i], LOW);  // turn RGB LED on
    delay(250);  // wait a quarter second
    digitalWrite(ledPins[i], HIGH); // turn the RGB LED off
    // Note that a HIGH turns the RGB LED off, LOW is on
    // that's backwards from the white LEDs
  }
  ////////////////////////////////////////////

  //Switch
  pinMode(switchPin, INPUT);  // set the switch as an input
  digitalWrite(switchPin, HIGH);  // enable the pull-up resistor

  //Button
  pinMode(buttonPin, INPUT);  // set the pin as an input
  digitalWrite(buttonPin, HIGH);  // enable the pull-up resistor

  //VIBE
  pinMode(vibePin, OUTPUT);  // set the pin as an output

  //Buzzer
  pinMode(buzzerP, OUTPUT);  // set both buzzer pins as outputs
  pinMode(buzzerN, OUTPUT);

  Serial.begin(9600);  // We'll output some information over serial
}

// the loop routine runs over and over again forever:
void loop() {
  
//Buzzer
  if(digitalRead(buttonPin) == 0)
  {  // if you press the button, make a short buzz
  
  //tone(pin, note, duration)
    tone(7,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(7,LA3,Q);
    delay(1+Q);
    tone(7,LA3,Q);
    delay(1+Q);
    tone(7,F3,E+S);
    delay(1+E+S);
    tone(7,C4,S);
    delay(1+S);
    
    tone(7,LA3,Q);
    delay(1+Q);
    tone(7,F3,E+S);
    delay(1+E+S);
    tone(7,C4,S);
    delay(1+S);
    tone(7,LA3,H);
    delay(1+H);
    
    tone(7,E4,Q); 
    delay(1+Q); 
    tone(7,E4,Q);
    delay(1+Q);
    tone(7,E4,Q);
    delay(1+Q);
    tone(7,F4,E+S);
    delay(1+E+S);
    tone(7,C4,S);
    delay(1+S);
    
    tone(7,Ab3,Q);
    delay(1+Q);
    tone(7,F3,E+S);
    delay(1+E+S);
    tone(7,C4,S);
    delay(1+S);
    tone(7,LA3,H);
    delay(1+H);
    
    tone(7,LA4,Q);
    delay(1+Q);
    tone(7,LA3,E+S);
    delay(1+E+S);
    tone(7,LA3,S);
    delay(1+S);
    tone(7,LA4,Q);
    delay(1+Q);
    tone(7,Ab4,E+S);
    delay(1+E+S);
    tone(7,G4,S);
    delay(1+S);
    
    tone(7,Gb4,S);
    delay(1+S);
    tone(7,E4,S);
    delay(1+S);
    tone(7,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(7,Bb3,E);
    delay(1+E);
    tone(7,Eb4,Q);
    delay(1+Q);
    tone(7,D4,E+S);
    delay(1+E+S);
    tone(7,Db4,S);
    delay(1+S);
    
    tone(7,C4,S);
    delay(1+S);
    tone(7,B3,S);
    delay(1+S);
    tone(7,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(7,F3,E);
    delay(1+E);
    tone(7,Ab3,Q);
    delay(1+Q);
    tone(7,F3,E+S);
    delay(1+E+S);
    tone(7,LA3,S);
    delay(1+S);
    
    tone(7,C4,Q);
    delay(1+Q);
     tone(7,LA3,E+S);
    delay(1+E+S);
    tone(7,C4,S);
    delay(1+S);
    tone(7,E4,H);
    delay(1+H);
    
     tone(7,LA4,Q);
    delay(1+Q);
    tone(7,LA3,E+S);
    delay(1+E+S);
    tone(7,LA3,S);
    delay(1+S);
    tone(7,LA4,Q);
    delay(1+Q);
    tone(7,Ab4,E+S);
    delay(1+E+S);
    tone(7,G4,S);
    delay(1+S);
    
    tone(7,Gb4,S);
    delay(1+S);
    tone(7,E4,S);
    delay(1+S);
    tone(7,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(7,Bb3,E);
    delay(1+E);
    tone(7,Eb4,Q);
    delay(1+Q);
    tone(7,D4,E+S);
    delay(1+E+S);
    tone(7,Db4,S);
    delay(1+S);
    
    tone(7,C4,S);
    delay(1+S);
    tone(7,B3,S);
    delay(1+S);
    tone(7,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(7,F3,E);
    delay(1+E);
    tone(7,Ab3,Q);
    delay(1+Q);
    tone(7,F3,E+S);
    delay(1+E+S);
    tone(7,C4,S);
    delay(1+S);
    
    tone(7,LA3,Q);
    delay(1+Q);
     tone(7,F3,E+S);
    delay(1+E+S);
    tone(7,C4,S);
    delay(1+S);
    tone(7,LA3,H);
    delay(1+H);
    
    delay(2*H);
 
  }
  else  // If the button is not pressed go in here
  {
    if(digitalRead(switchPin) == 0)
    {  // If the switch is on, vibrate
      digitalWrite(vibePin, HIGH);
      delay(100);
      digitalWrite(vibePin, LOW); 
  
    }
    
    ///LIGHT TEST
    if(analogRead(lightSensorPin) < 20){
      //if its dark, turn on all white leds...
      
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], HIGH);
      digitalWrite(ledPins[4], HIGH);
      
    }
    else{
      // if it's light, turn them off...
      for(int i=0;i<5;i++)
      {
        digitalWrite(ledPins[i], LOW);
      }
    }

    ///TEMP TEST 
     // Note that a HIGH turns the RGB LED off, LOW is on
     // that's backwards from the white LED
    if(analogRead(tempSensorPin) > 150)
    {
      //if the tech puts a little hot air over the temp sensor it will raise to at least 170
      digitalWrite(ledPins[5], LOW); //Turn on red LED - to indicate "hot"
    }
    else{
      digitalWrite(ledPins[5], HIGH);  // turn the red LED off
    }
    
    /* from here on down, we'll just print out the status of every input */
    Serial.print("Switch=");
    Serial.print(digitalRead(switchPin));

    Serial.print("  Temp=");
    Serial.print(analogRead(tempSensorPin));
    
    Serial.print("  Button=");
    Serial.print(digitalRead(buttonPin));

    Serial.print("  Light=");
    Serial.println(analogRead(lightSensorPin)); 
  }  
     
}


/* ProtoSnap LilyPad Development Platform Example Code
  Original by: Pete Lewis
      SparkFun Electronics
  date: 8/24/11
  Modified by : Caroline D. Hardin 10-21-15
  Music by: Eserra at http://www.instructables.com/id/How-to-easily-play-music-with-buzzer-on-arduino-Th/
  license: Creative Commons Attribution-Share-alike v3.0 CC BY-SA 3.0
  http://creativecommons.org/licenses/by-sa/3.0/
  
  This is example code for the Protosnap LilyPad Development Platform
  It'll do a quick startup sequence, flashing all LEDs, then it'll go int the loop.
  In the loop it'll check for button or switch presses, and buzz or vibrate
  depending on if they're engaged.
  If neither switch is on, it'll check the light sensor and temperature sensor,
  and light up some LEDs if the proper values are met. Hold your finger over the
  light sensor to turn the white LEDs on. Try blowing on the temperature sensor to
  turn the red LED on.
  Finally, the status of each input is streamed over the serial line at 9600 bps.
  To see what the values are, open up the serial monitor (the top right icon)
  and make sure the baud is set to 9600.
*/
