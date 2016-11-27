/* Pin Definitions */
int red = 9;
int green = 11;
int blue = 10;

int lightSensorPin = A6;
int tempSensorPin = A1;


void setup()
{
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    
    digitalWrite(red, HIGH); 
    digitalWrite(blue, HIGH); 
    digitalWrite(green, HIGH);   

}

void loop()
{
  
    //if it's dark (the light sensor sees less than 20)
    if(analogRead(lightSensorPin) < 20){
   
      //Blink red
      digitalWrite(red, LOW);
      delay(250);
      digitalWrite(red, HIGH);
      
      //Blink blue
      digitalWrite(blue, LOW);
      delay(250);
      digitalWrite(blue, HIGH); 
      
      //Blink green
      digitalWrite(green, LOW);
      delay(250);
      digitalWrite(green, HIGH); 
     
      
    }
    else{ //it's not dark
      
      //so turn all the lights off
      digitalWrite(red, HIGH); 
      digitalWrite(blue, HIGH);
      digitalWrite(green, HIGH);
    }   
 

    
}





