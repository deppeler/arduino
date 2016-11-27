/** SETUP
 *  BOARD: LilyPad Arduino
 *  PROCESSOR: ATMega325
 *  PORT: COM4
 *  PROGRAMMER: AVRISP mkll
 */

//Motor   3
//RGB LED - Red   9
//RGB LED - Blue  10
//RGB LED - Green   11
//Button  A5
//Slide Switch  2
//White LED's   5, 6, A2, A3, A4
//Buzzer (+)  7
//Buzzer (-)  12
//Light Sensor  A6
//Temp Sensor   A1

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  shortTone();
  shortTone();
  shortTone();
  longTone();
  longTone();
  longTone();
  shortTone();
  shortTone();
  shortTone();
  delay(3000);
}

void shortTone() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(250);
}

void longTone() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(250);
}

