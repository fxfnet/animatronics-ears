#include <Servo.h> //on appelle la bibliotheque qui gere les servomoteurs

Servo servoturnL; //nom du servo qui gere l'axe oreille Gauche
Servo servotiltL; //nom du servo qui gere le tilt oreille Gauche
Servo servoturnR; //nom du servo qui gere l'axe oreille Droite
Servo servotiltR; //nom du servo qui gere le tilt oreille Droite
const int  buttonPin = 3;
int buttonState = 0;


void setup() {
  Serial.begin(9600); 
  servoturnL.attach(2);
  servoturnL.write(55); 
  servotiltL.attach(4);
  servotiltL.write(33); 
  servoturnR.attach(5);
  servoturnR.write(80); 
  servotiltR.attach(6);
  servotiltR.write(75); 
  pinMode(buttonPin, INPUT);

}

void loop() {
  //oreille gauche turn : vers l'arriere 120 ; vers l'avant 25
  //oreille gauche tilt : penche 75 ; droit  33
  //oreille droite turn : vers l'arriere 25 ; vers l'avant 120
  //oreille droite tilt : penche 33 ; droit  75 
buttonState = digitalRead(buttonPin);  // Read the button position
  if (buttonState == HIGH) {
// vers l'avant extreme 
  servoturnL.write(25); 
  servotiltL.write(33);    
  servoturnR.write(120); 
  servotiltR.write(75);    
  delay(2000);
//aux extrèmes
  servoturnL.write(120); 
  servotiltL.write(75);   
  servoturnR.write(25); 
  servotiltR.write(33);   
  delay(500);
//sequence nawak
  servoturnL.write(55); 
  servotiltL.write(33);    
  servoturnR.write(25); 
  servotiltR.write(75);
  delay(300);
  servotiltR.write(33);   
  delay(300);
  servotiltR.write(75);
  delay(300);
  servotiltR.write(33);   
  servotiltL.write(75);   
  delay(500);
// retour à l'initiale
  servoturnL.write(55); 
  servotiltL.write(33);    
  servoturnR.write(80); 
  servotiltR.write(75);    
  delay(2000);}}

// Surprise / en colère / triste / clin d'oreille
// Presser & relacher / presser et maintenir / presser deux fois...
