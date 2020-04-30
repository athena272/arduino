/*---------Entrandas e Saídas Digitais-----------------------
*
*4) Faça com que o LED acenda ao receber qualquer letra maiúscula, 
*e apague ao receber qualquer letra minúscula. 
*/
 //Declaração de variávies globais

const byte LED_1 = 13;

void setup() {    
    pinMode(LED_1, OUTPUT); //LED como dispositivo de saíde
    Serial.begin(9600); // Iniciar Monitor Serial
}
void loop() {
    
  char Maiusculas_acende; 
  byte Conversao_ASCII = Maiusculas_acende;
  
  delay(500);
  if ( Serial.available() > 0 ){ 
    Maiusculas_acende = Serial.read();      
    Serial.print(Maiusculas_acende);   
    Serial.print("|");
    Serial.println( Conversao_ASCII);
  //------------------------------------------
  }
  if (Conversao_ASCII >= 65 and Conversao_ASCII <= 90){ //Qualquer valor no range A-Z
  digitalWrite(LED_1, HIGH); //Acende o LED
  } 
  else if (Conversao_ASCII >= 97 and Conversao_ASCII <= 122){ //Qualquer valor no range a-z
    digitalWrite(LED_1, LOW); //Desliga o LED
  }
}
