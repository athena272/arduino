/*---------Entrandas e Saídas Digitais-----------------------
*
*Considere somente 1 LED (pino 13), e 1 botão (pino 5). 
*C)Faça com que o LED pisque, com período 1s, quando o botão for pressionado, 
* e apague, caso contrário.
*/
 //Declaração de variávies globais

const byte LED_1 = 13;

const byte BUTTON_1 = 5;

void setup() {    
    pinMode(LED_1, OUTPUT); //LED como dispositivo de saíde
    pinMode(BUTTON_1, INPUT); //BOTAO como dispositivo de entrada
    Serial.begin(9600); // Iniciar Monitor Serial
}
void loop() {
  delay(100); //Diminuir velocidade com a qual os dados são mostrados
  bool bt = digitalRead(BUTTON_1); //Receber em valor boleano a leitura da variavel(HIGH or LOW) 
  Serial.print("botão = "); //Escreve a mensagem 
  Serial.println( bt ); //Escreve O valor da variável "bt"
  if(bt == true){ //Se for (verdadeiro/HIGH/1) então...
    digitalWrite(LED_1, HIGH); //Acende o LED
    delay(1000);
    digitalWrite(LED_1, LOW); //Desliga o LED
    delay(1000);
    digitalWrite(LED_1, HIGH); //Acende o LED
    delay(1000);
     digitalWrite(LED_1, LOW); //Desliga o LED
    delay(1000);
    digitalWrite(LED_1, HIGH); //Acende o LED
    delay(1000);
     digitalWrite(LED_1, LOW); //Desliga o LED
    delay(1000);
  }
  else{ //Se não 
  digitalWrite(LED_1, LOW);//Desliga o LED
  }
}
