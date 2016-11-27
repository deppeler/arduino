#include "pitches.h"

//the switch is on pin2
int switchPin = 2;

//the buzzer is on pin 7
int buzzer = 7;

// we'll store all the notes for 'let it go' in a list:
int letitgo[] = {
NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_GS4, 0, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_AS4, 0, NOTE_GS4, NOTE_F4, 
//Let it go -- let it go. -- Can't
NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_AS4, 0, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_GS4, 0, NOTE_DS4, 

NOTE_C5, NOTE_C5, 
//hold it back an-y more--  Let it go -- let it go-----
NOTE_AS4, 0, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_AS4, 

NOTE_GS4, 0, 
//-- Turn a-way- and slam - the - door
NOTE_DS5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, 0, NOTE_GS4, NOTE_GS4, NOTE_DS5, NOTE_DS5, 0, NOTE_C5, NOTE_C5, 

NOTE_GS4, 
//I - don't care - What they're going to - say --
0, 0, NOTE_GS4, NOTE_GS4, NOTE_G4, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, 0, NOTE_CS4, 
//-- let the storm rage on -- The
NOTE_CS4, NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_CS4, NOTE_C4, NOTE_GS3, 
//cold never bothered me anyway.
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
8, 8, 8, 2, 8, 8, 8, 8, 2, 4, 8, 8, 
8, 8, 4, 8, 4, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 8, 
2, 8, 8, 8, 4, 4, 4, 8, 8, 8, 8, 4, 2, 2, 
4, 8, 8, 4, 2, 4, 4, 4, 4, 8, 8, 4, 2, 
4, 4, 8, 8, 4, 8, 8, 4, 1, 8, 8, 
4, 8, 8, 8, 8, 8, 8, 8, 4};
 
void setup() { 

  //Switch
  pinMode(switchPin, INPUT); 	 // set the switch as an input
  digitalWrite(switchPin, HIGH); // enable the pull-up resistor

  //Buzzer
  pinMode(buzzer, OUTPUT);  	// set the buzzer pins as outputs

}

// the loop routine runs over and over again forever:
void loop() {
  
  //if the switch is on, play the song once
  if(digitalRead(switchPin) == 0)
  {  
    //for every note in the song, play it for the proper length
      for (int thisNote = 0; thisNote < (sizeof(noteDurations)/2); thisNote++) {
  
      // to calculate the note duration, take one second (1000)
      //divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      tone(buzzer, letitgo[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 20% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.2;
      delay(pauseBetweenNotes);
      
      // stop the tone playing:
      noTone(buzzer);
      }
  }
  
}
     
//code adapted from http://www.instructables.com/id/Musical-Snow-Globe/
