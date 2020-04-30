/*---------Entrandas e Saídas Digitais-----------------------
*
*2) Considere somente 1 LED (pino 13), e 2 botões (pinos 5 e 4): 
*   DICA: use Operadores Booleanos ( && e || )
*   A) Faça com que o LED acenda quando o botão 1 for pressionado, e apague, somente quando o botão 2 for pressionado
*
*/
 //Declaração de variávies globais

const byte LED_1 = 13;

const byte BUTTON_1 = 5;

const byte BUTTON_2 = 4;

void setup() {    
    pinMode(LED_1, OUTPUT); //LED como dispositivo de saíde
    pinMode(BUTTON_1, INPUT); //BOTAO_1 como dispositivo de entrada
    pinMode(BUTTON_2, INPUT); //BOTAO_2 como dispositivo de entrada
    Serial.begin(9600); // Iniciar Monitor Serial
}
void loop() {
  delay(100); //Diminuir velocidade com a qual os dados são mostrados
  bool bt_1 = digitalRead(BUTTON_1); //Receber em valor boleano a leitura da variavel(HIGH or LOW) 
  bool bt_2 = digitalRead(BUTTON_2); //Receber em valor boleano a leitura da variavel(HIGH or LOW)
  Serial.print("botão_1 = "); //Escreve a mensagem 
  Serial.println( bt_1 ); //Escreve O valor da variável "bt"
  Serial.print("botão_2 = ");
  Serial.println( bt_2 );
  if(bt_1 == true){ //Se for (verdadeiro/HIGH/1) então...
    digitalWrite(LED_1, HIGH); //Acende o LED eterno
  }
  if(bt_2 == true){ //Se for (verdadeiro/HIGH/1) então...
    digitalWrite(LED_1, LOW);//Desliga o LED que estava ligado eterno
  }
}
