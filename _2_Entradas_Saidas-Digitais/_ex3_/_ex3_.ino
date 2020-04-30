/*---------Entrandas e Saídas Digitais-----------------------
*
*3) Faça com que o LED acenda ao receber o caractere ‘A’ da Serial, 
*e apague quando receber o caractere ‘a’
*/
 //Declaração de variávies globais

const byte LED_1 = 13;

void setup() {    
    pinMode(LED_1, OUTPUT); //LED como dispositivo de saíde
    Serial.begin(9600); // Iniciar Monitor Serial
}
void loop() {
    
  char A_or_a; 
  delay(500);
  if ( Serial.available() > 0 ){ 
    A_or_a = Serial.read();      
    Serial.print(A_or_a);     
  }
  if (A_or_a == 'A'){
  digitalWrite(LED_1, HIGH);
  }
  else if (A_or_a == 'a'){
    digitalWrite(LED_1, LOW);
  }
}
