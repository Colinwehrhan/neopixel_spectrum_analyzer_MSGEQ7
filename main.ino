 /*

 A sketch that grabs the frequency signal level measured by the Mixed Signal
 Integration MSGEQ7. This sketch is designed to work with the MSGEQ7 Breakout Board 
 available at the Rheingold Heavy website.
 
 This sketch expects the following pin assignments...
 STROBE = DIGITAL 7
 RESET  = DIGITAL 8
 OUTPUT = ANALOG  5
 */
 int strobePin  = 7;    // Strobe Pin on the MSGEQ7
int resetPin   = 8;    // Reset Pin on the MSGEQ7
int outPin     = A5;   // Output Pin on the MSGEQ7
int integerArray[7];          // An array to hold the values from the 7 frequency bands
int columns = 0;


// setup the adafruit libraries
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

// set the pin for the lights
#define PIN 6

// setup the matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(7, 7, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
 
const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() 
{

   // get the matrix ready
   matrix.begin();
  Serial.begin (9600);

  // Define our pin modes
  pinMode      (strobePin, OUTPUT);
  pinMode      (resetPin,  OUTPUT);
  pinMode      (outPin,    INPUT);

  // Create an initial state for our pins
  digitalWrite (resetPin,  LOW);
  digitalWrite (strobePin, LOW);
  delay        (1);

  // Reset the MSGEQ7 as per the datasheet timing diagram
  digitalWrite (resetPin,  HIGH);
  delay        (1);
  digitalWrite (resetPin,  LOW);
  digitalWrite (strobePin, HIGH);
  delay        (1);


}
void loop() 
{
  
  // Cycle through each frequency band by pulsing the strobe.
  for (int i = 0; i < 7; i++) 
  {
    digitalWrite       (strobePin, LOW);
    delayMicroseconds  (100);                    // Delay necessary due to timing diagram
    integerArray[i] =         analogRead (outPin);
    digitalWrite       (strobePin, HIGH);
    delayMicroseconds  (100);                    // Delay necessary due to timing diagram  
  }

// loop through the columumns of the array & columns of the leds ( they are same
    for( columns = 0; columns < 7; columns++)
    {
      
      
      // check what the value of the that array is and set accordinlgy CASE SWITCH
      
        // if between 0 - 149
        if( integerArray[columns] <= 149)
          {
            // draw the first pixel green
            matrix.drawPixel(columns, 6, matrix.Color(0, 255, 0));
            
           // turn off others
           
            matrix.drawPixel(columns, 5, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 4, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 3, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 2, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 1, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 0, matrix.Color(0, 0, 0));
            matrix.show();
          }  
          
        // if bettween 150 - 299
          if( integerArray[columns] >= 150 && integerArray[columns] <= 299)
          {
            // draw the first pixel green
            matrix.drawPixel(columns, 6, matrix.Color(0, 255, 0));
            
            matrix.drawPixel(columns, 5, matrix.Color(0, 255, 0));
            
            // turn off others
            
            matrix.drawPixel(columns, 4, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 3, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 2, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 1, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 0, matrix.Color(0, 0, 0));
            matrix.show();
          }  
        // if between 300 - 449
          if( integerArray[columns] >= 300 && integerArray[columns] <= 449)
          {
            // draw the first pixel green
            matrix.drawPixel(columns, 6, matrix.Color(0, 255, 0));
            
            matrix.drawPixel(columns, 5, matrix.Color(0, 255, 0));
            
            matrix.drawPixel(columns, 4, matrix.Color(0, 255, 0));
            
            // turn off others
            
            matrix.drawPixel(columns, 3, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 2, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 1, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 0, matrix.Color(0, 0, 0));
            matrix.show();
          }  
        
        // if between 450- 599
          if( integerArray[columns] >= 450 && integerArray[columns] <= 599)
          {
            // draw the first pixel green
            matrix.drawPixel(columns, 6, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 5, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 4, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 3, matrix.Color(0, 255, 0));
            
            // turn off others
            
            matrix.drawPixel(columns, 2, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 1, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 0, matrix.Color(0, 0, 0));
            matrix.show();
          }  
          
        // if between 600 - 749
          if( integerArray[columns] >= 600 && integerArray[columns] <= 749)
          {
            // draw the first pixel green
            matrix.drawPixel(columns, 6, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 5, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 4, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 3, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 2, matrix.Color(255, 255, 0));
           
            // turn off others
            matrix.drawPixel(columns, 1, matrix.Color(0, 0, 0));
            matrix.drawPixel(columns, 0, matrix.Color(0, 0, 0));
            matrix.show();
          }          
        // if between 750 -899
          if( integerArray[columns] >= 750 && integerArray[columns] <= 899)
          {
            // draw the first pixel green
            matrix.drawPixel(columns, 6, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 5, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 4, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 3, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 2, matrix.Color(255, 255, 0));
            matrix.drawPixel(columns, 1, matrix.Color(255, 0, 0));
            
            // turn off others
            matrix.drawPixel(columns, 0, matrix.Color(0, 0, 0));
            matrix.show();
          }   
        // if between 900 - 1000
          if( integerArray[columns] >= 900)
          {
            // draw the first pixel green
            matrix.drawPixel(columns, 6, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 5, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 4, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 3, matrix.Color(0, 255, 0));
            matrix.drawPixel(columns, 2, matrix.Color(255, 255, 0));
            matrix.drawPixel(columns, 1, matrix.Color(255, 0, 0));
            matrix.drawPixel(columns, 0, matrix.Color(255, 0, 0));
            matrix.show();
          }           
        
        
        // reset the columns when it reaches the end
        
      
      
    }


delay(20);

}

