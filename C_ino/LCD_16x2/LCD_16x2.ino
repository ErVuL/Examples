// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
/**********************************************************/
char array1[]="Ecran LCD 16x2            "; //the string to print on the LCD
char array2[]=" Arduino UNO              "; //the string to print on the LCD
int tim = 500; //the value of delay time

byte incomingByte = 0;

const int pinLedR = 9;
const int pinLedG = 11;
const int pinLedB = 10;

int colorR = 0;
int colorG = 0;
int colorB = 0;

int R = 0;
int G = 0;
int B = 0;

#define TIME 1


// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x3F,20,4);
/*********************************************************/
void setup()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 
  Serial.begin(9600);
  pinMode(pinLedR,OUTPUT);
  pinMode(pinLedG,OUTPUT);
  pinMode(pinLedB,OUTPUT);
}
/*********************************************************/
void loop() 
{
  lcd.setCursor(16,0); // set the cursor to column 15, line 0
  for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
  {
    lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
    lcd.print(array1[positionCounter1]); // Print a message to the LCD.
    delay(tim); //wait for 250 microseconds
  }
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left  corner.
  lcd.setCursor(16,1); // set the cursor to column 15, line 1
  for (int positionCounter = 0; positionCounter < 26; positionCounter++)
  {
    lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
    lcd.print(array2[positionCounter]); // Print a message to the LCD.
    delay(tim); //wait for 250 microseconds
  }
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left corner.

  if (Serial.available() > 0) {
      incomingByte = Serial.read();
      Serial.write(incomingByte);
  }
  if ( (unsigned char)incomingByte == 'R'){
      if (Serial.available() > 0) {
      R = Serial.read();
      Serial.write(R);
  }}
    if ( (unsigned char)incomingByte == 'G'){
      if (Serial.available() > 0) {
      G = Serial.read();
      Serial.write(G);
  }}
    if ( (unsigned char)incomingByte == 'B'){
      if (Serial.available() > 0) {
      B = Serial.read();
      Serial.write(B);
  }}
    changeColor(R,G,B);
}



  
void changeColor(int newR, int newG, int newB) {
      
  // On boucle de 0 à 255 inclus pour faire 256 transitions
  for ( int i = 0 ; i < 256 ; i++ ) {
          
    // On map la couleur à afficher chaque étape de la transition
    int r = map(i, 0, 255, colorR, newR);
    int g = map(i, 0, 255, colorG, newG);
    int b = map(i, 0, 255, colorB, newB);
          
    // On affiche la couleur
    analogWrite(pinLedR, r);
    analogWrite(pinLedG, g);
    analogWrite(pinLedB, b);
           
    // On attend un peu
    delay(TIME);
          
  }
      
  // Et pour finir, on sauvegarde cette nouvelle couleur
  colorR = newR;
  colorG = newG;
  colorB = newB;
      
}
