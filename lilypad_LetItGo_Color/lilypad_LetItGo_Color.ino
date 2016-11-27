#include "pitches_color.h"

//the switch is on pin2
int switchPin = 2;

//the buzzer is on pin 7
int buzzer = 7;

// connect the tri-color pins
int redPin   =  9;  // R petal on RGB LED module connected to digital pin  9 
int greenPin = 11;  // G petal on RGB LED module connected to digital pin 11
int bluePin  = 10;  // B petal on RGB LED module connected to digital pin 10


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

// SET the red component for each note
int R[] = {
R_F, R_G, R_GS, R_GS, 0, R_DS, R_DS, R_AS, R_AS, 0, R_GS, R_F, 
//Let it go -- let it go. -- Can't
R_F, R_F, R_F, R_F, R_G, R_AS, R_AS, 0, R_F, R_G, R_GS, R_GS, 0, R_DS, 

R_C, R_C, 
//hold it back an-y more--  Let it go -- let it go-----
R_AS, 0, R_GS, R_AS, R_C, R_C, R_CS, R_C, R_AS, R_GS, R_AS, 

R_GS, 0, 
//-- Turn a-way- and slam - the - door
R_DS, R_C, R_C, R_C, R_AS, 0, R_GS, R_GS, R_DS, R_DS, 0, R_C, R_C, 

R_GS, 
//I - don't care - What they're going to - say --
0, 0, R_GS, R_GS, R_G, 0, R_DS, R_DS, R_DS, 0, R_CS, 
//-- let the storm rage on -- The
R_CS, R_CS, R_C, R_CS, R_C, R_CS, R_CS, R_C, R_GS, 
//cold never bothered me anyway.
};

// SET the blue component for each note
int B[] = {
B_F, B_G, B_GS, B_GS, 0, B_DS, B_DS, B_AS, B_AS, 0, B_GS, B_F, 
//Let it go -- let it go. -- Can't
B_F, B_F, B_F, B_F, B_G, B_AS, B_AS, 0, B_F, B_G, B_GS, B_GS, 0, B_DS, 

B_C, B_C, 
//hold it back an-y more--  Let it go -- let it go-----
B_AS, 0, B_GS, B_AS, B_C, B_C, B_CS, B_C, B_AS, B_GS, B_AS, 

B_GS, 0, 
//-- Turn a-way- and slam - the - door
B_DS, B_C, B_C, B_C, B_AS, 0, B_GS, B_GS, B_DS, B_DS, 0, B_C, B_C, 

B_GS, 
//I - don't care - What they're going to - say --
0, 0, B_GS, B_GS, B_G, 0, B_DS, B_DS, B_DS, 0, B_CS, 
//-- let the storm rage on -- The
B_CS, B_CS, B_C, B_CS, B_C, B_CS, B_CS, B_C, B_GS, 
//cold never bothered me anyway.
};

// SET the green component for each note
int G[] = {
G_F, G_G, G_GS, G_GS, 0, G_DS, G_DS, G_AS, G_AS, 0, G_GS, G_F, 
//Let it go -- let it go. -- Can't
G_F, G_F, G_F, G_F, G_G, G_AS, G_AS, 0, G_F, G_G, G_GS, G_GS, 0, G_DS, 

G_C, G_C, 
//hold it back an-y more--  Let it go -- let it go-----
G_AS, 0, G_GS, G_AS, G_C, G_C, G_CS, G_C, G_AS, G_GS, G_AS, 

G_GS, 0, 
//-- Turn a-way- and slam - the - door
G_DS, G_C, G_C, G_C, G_AS, 0, G_GS, G_GS, G_DS, G_DS, 0, G_C, G_C, 

G_GS, 
//I - don't care - What they're going to - say --
0, 0, G_GS, G_GS, G_G, 0, G_DS, G_DS, G_DS, 0, G_CS, 
//-- let the storm rage on -- The
G_CS, G_CS, G_C, G_CS, G_C, G_CS, G_CS, G_C, G_GS, 
//cold never bothered me anyway.
};
 
void setup() { 

  // Tri-color
  pinMode(redPin, OUTPUT);  // sets the redPin to be an output
  pinMode(greenPin, OUTPUT);    // sets the greenPin to be an output
  pinMode(bluePin, OUTPUT);   // sets the bluePin to be an input

  //Switch
  pinMode(switchPin, INPUT);    // set the switch as an input
  digitalWrite(switchPin, HIGH); // enable the pull-up resistor

  //Buzzer
  pinMode(buzzer, OUTPUT);    // set the buzzer pins as outputs

}

// the loop routine runs over and over again forever:
void loop() {
  
  //if the switch is on, play the song once
  if(digitalRead(switchPin) == 0)
  {  
    //for every note in the song, play it for the proper length and set the color
      for (int thisNote = 0; thisNote < (sizeof(noteDurations)/2); thisNote++) {
  
      // to calculate the note duration, take one second (1000)
      //divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      color(R[thisNote],G[thisNote],B[thisNote]);
      tone(buzzer, letitgo[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 20% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.2;
      delay(pauseBetweenNotes);
      
      // stop the tone playing:
      noTone(buzzer);
      }
  }

  // Turn the color off after the song stops
  color(0,0,0);
  
}

void color (unsigned char red, unsigned char green, unsigned char blue)   //the color generating function 
{    
         analogWrite(redPin, 255-red);   
         analogWrite(bluePin, 255-blue);   
         analogWrite(greenPin, 255-green);       

}
//code adapted from http://www.instructables.com/id/Musical-Snow-Globe/
