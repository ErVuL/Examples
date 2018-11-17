//Définition des pins de la led RVB
const int pinLedR = 9;
const int pinLedG = 10;
const int pinLedB = 11;
 
//Mise à 0 des premiers termes de chaque led pour le mappage
int colorR = 0;
int colorG = 0;
int colorB = 0;
 
//temps de pause défini à chaque itération
//Temps total pour la loop (en milliseconde) = 6*255*TIME = 1530*TIME
//Pour une boucle de 1 minute : TIME = 60000/1530 = 39
#define TIME 1
 
void setup() { 
   
  pinMode(pinLedR,OUTPUT);
  pinMode(pinLedG,OUTPUT);
  pinMode(pinLedB,OUTPUT);
   
}
 
void loop() {
 
  //Appel de la fonction pour changer la couleur avec les différentes valeurs
  changeColor(255,0,0);
  changeColor(255,255,0);
  changeColor(0,255,0);
  changeColor(0,255,255);
  changeColor(0,0,255);
  changeColor(255,0,255);
     
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
