//Définition des pins de la led RVB
const int pinLedR = 9;
const int pinLedG = 11;
const int pinLedB = 10;
 
//Mise à 0 des premiers termes de chaque led pour le mappage
int colorR = 0;
int colorG = 0;
int colorB = 0;

int R = 0;
int G = 0;
int B = 0;

byte incomingByte = 0;   // for incoming serial data

//temps de pause défini à chaque itération
//Temps total pour la loop (en milliseconde) = 6*255*TIME = 1530*TIME
//Pour une boucle de 1 minute : TIME = 60000/1530 = 39
#define TIME 1
 
void setup() { 
  Serial.begin(9600);
  
  pinMode(pinLedR,OUTPUT);
  pinMode(pinLedG,OUTPUT);
  pinMode(pinLedB,OUTPUT);
   
}
 
void loop() {

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
