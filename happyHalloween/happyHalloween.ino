/* https://www.arduino.cc/en/Reference/LiquidCrystal
 * BOARD: ARDUINO/GENUINO UNO CARD
 * PORT: COM3 (GENUINO UNO)
 * PROGRAMMER: AVRISP mkll
 * 
 * =====================================================
 * WIRING:
 *   LCD         to ARDUINO UNO
 * -----------------------------------------------------
 * 1 GND
 * 2 5V
 * 3 LCD Vcc     to GREEN pin on poteniometer control
 * 4 LCD RS      to ARDUINO DIG 12
 * 5 LCD R/W     to ARDUINO GND
 * 6 LCD ENABLE  to ARDUINO DIG ~11 (PWM)
 * 7
 * 8
 * 9
 * 10
 * 11 LCD D4     to ARDUINO DIG ~5 (PWM)
 * 12 LCD D5     to ARDUINO DIG  4
 * 13 LCD D6     to ARDUINO DIG ~3 (PWM)
 * 14 LCD D7     to ARDUINO DIG  2
 * 15 LCD
 * 16 LCD
 * =====================================================
 */

/* LiquidCrystal commands
 *  Function

LiquidCrystal() - Creates a variable of type LiquidCrystal.
 The display can be controlled using 4 or 8 data lines.
 If the former, omit the pin numbers for d0 to d3 and
 leave those lines unconnected. The RW pin can be tied
 to ground instead of connected to a pin on the Arduino;
 if so, omit it from this function's parameters.

LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)
LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)

LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
Parameters
rs: the number of the Arduino pin that is connected to the RS pin on the LCD
rw: the number of the Arduino pin that is connected to the RW pin on the LCD (optional)
enable: the number of the Arduino pin that is connected to the enable pin on the LCD
d0, d1, d2, d3, d4, d5, d6, d7: the numbers of the Arduino pins that are connected 
to the corresponding data pins on the LCD. d0, d1, d2, and d3 are optional; 
if omitted, the LCD will be controlled using only the four data lines (d4, d5, d6, d7).

   begin(cols,rows) - Initializes the interface to the LCD screen,
             and specifies the dimensions (width and height)
             of the display. begin() needs to be called before
             any other LCD library commands.
   clear() - Clears the LCD screen and positions the cursor in the upper-left corner.
   home()  - Positions the cursor in the upper-left of the LCD.
             That is, use that location in outputting subsequent
             text to the display. To also clear the display, use
             the clear() function instead.
   setCursor(col,row) - Position the LCD cursor;
             set the location at which subsequent text written
             to the LCD will be displayed. (0-based indexing)
   write() - write a character to the LCD
   print(data) - prints text to the LCD
   print(data,BASE) - prints values in the BASE to the LCD
   cursor() - Display the LCD cursor: an underscore (line) at the
              position to which the next character will be written.
   noCursor() - Hides the LCD cursor.
   blink() - Display the blinking LCD cursor. If used in combination with the
             cursor() function, the result will depend on the particular display.
   noBlink() - Turns off the blinking LCD cursor.
   display() - Turns on the LCD display, after it's been turned
               off with noDisplay(). This will restore the text
               (and cursor) that was on the display.
   noDisplay() - Turns off the LCD display, without losing the text currently shown on it.
   scrollDisplayLeft() - Scrolls the contents of the display (text and cursor) one space to the left.
   scrollDisplayRight() - Scrolls the contents of the display (text and cursor) one space to the right.
   autoscroll() - Turns on automatic scrolling of the LCD.
                  This causes each character output to the display
                  to push previous characters over by one space.
                  If the current text direction is left-to-right
                  (the default), the display scrolls to the left;
                  if the current direction is right-to-left,
                  the display scrolls to the right.
                  This has the effect of outputting each new
                  character to the same location on the LCD.
   noAutoscroll() - Turns off automatic scrolling of the LCD.
   leftToRight() - Set the direction for text written to the LCD to left-to-right,
                   the default. This means that subsequent characters
                   written to the display will go from left to right,
                   but does not affect previously-output text.
   rightToLeft() - Set the direction for text written to the LCD to right-to-left
                   (the default is left-to-right). This means that
                   subsequent characters written to the display will
                   go from right to left, but does not affect
                   previously-output text.
   createChar() -  Create a custom character (gylph) for use on the LCD.
                   Up to eight characters of 5x8 pixels are supported
                   (numbered 0 to 7). The appearance of each custom character
                   is specified by an array of eight bytes, one for each row.
                   The five least significant bits of each byte determine the
                   pixels in that row. To display a custom character on the
                   screen, write() its number.
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int columns = 16;
int rows = 2;

// define a smiley face character
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

// define a left half of a pumpkin character
byte pumpkinLeft[8] = {
  B00011,
  B01000,
  B10001,
  B10100,
  B10011,
  B01000,
  B00011,
};
// define right half of a pumpkin
byte pumpkinRight[8] = {
  B11000,
  B00010,
  B10001,
  B00101,
  B11001,
  B00010,
  B11000,
};

#define distancePin A0

// put your setup code here, to run once:
void setup() {

  // setup push button on digital 1
  pinMode(1,INPUT);

  // setup for the GP2Y0A21 distance sensor (analog)
  Serial.begin (9600);
  pinMode (distancePin, INPUT);

  // create a smiley face character
  lcd.createChar(0, smiley);

  // create left half of pumpkin character
  lcd.createChar(1, pumpkinLeft);

  // create right half of pumpkin character
  lcd.createChar(2, pumpkinRight);

  lcd.begin(columns, rows);
  lcd.print("Happy Halloween!");

}

// Display the distance read from sensor to serial port
void displayDistance (LiquidCrystal lcd) {
  uint16_t value = analogRead (distancePin);
  uint16_t range = get_gp2d12 (value);
  lcd.print(value);
  Serial.print("Value = ");
  Serial.print(value);
  Serial.print(" range = ");
  Serial.print (range);
  Serial.println (" mm");
  delay (500);
}


  void loop() {
  // put your main code here, to run repeatedly:
  //  lcd.noBlink();
  //  int pauseTime = 3000; // milliseconds
  //  delay(pauseTime);
  //
  //  lcd.blink();
  //  delay(pauseTime);

// IF button is pressed display distance TODO DOES NOT WORK
//if ( digitalRead(1) == HIGH ) {
 // lcd.print("BUTTON");
  //displayDistance(lcd);
//}

  uint16_t value = analogRead (distancePin);
  uint16_t range = get_gp2d12 (value);
//  writeSerial(value,range);

  if (range < 100) {
    // display a smiley face
    lcd.setCursor(0, 1);
    lcd.write(byte(0)); // displays the character created at 0 ???
    //lcd.write(byte(0)); // displays the character created at 0 ???
    lcd.print("   BACK UP!  ");
    lcd.write(byte(1)); // displays the character created at 0 ???
    lcd.write(byte(2)); // displays the character created at 0 ???
  } else {

    lcd.setCursor(0, 1);
//    lcd.print(value);
    lcd.print("COME CLOSER ");
    lcd.print(range);
    lcd.print(" mm     ");
  }
  delay(500);

}

// FROM:
// http://dfrobot.com/wiki/index.php/Sharp_GP2Y0A21_Distance_Sensor_%2810-80cm%29_%28SKU:SEN0014%29
uint16_t get_gp2d12 (uint16_t value) {
  if (value < 10) value = 10;
  return ((67870.0 / (value - 3.0)) - 40.0);
}

void writeSerial(uint16_t value, uint16_t range) {
  Serial.print("Value = ");
  Serial.print(value);
  Serial.print( " " );
  Serial.print(range);
  Serial.println(" mm");
}

