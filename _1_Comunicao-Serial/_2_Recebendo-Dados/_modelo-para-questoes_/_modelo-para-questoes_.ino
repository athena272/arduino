/*---------Entrandas e Saídas Digitais-----------------------
 * 
 */
 //Declaração de variávies globais
const byte LED_1 = 13;

const byte BUTTON_1 = 5;

void setup() {    
    pinMode(13, OUTPUT); //LED como dispositivo de saíde
    pinMode(5, INPUT); //BOTAO como dispositivo de entrada
    Serial.begin(9600); // Iniciar Monitor Serial
}
void loop() {
  delay(1000); //Diminuir velocidade com a qual os dados são mostrados
  bool bt = digitalRead(BUTTON_1);
  Serial.print("botão = ");
  Serial.println( bt );
}
