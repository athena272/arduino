/* ------------SAÍDAS PWM----------------
* O programa fará com que o brilho do LED conectado ao pino 11 aumente gradativamente. 
* O LED no pino 12 foi aceso somente para que você possa comparar visualmente o brilho dos dois…
-----------------------Exercício 3 A:-----------------------------------
*A) Considere agora o Arduino conectado a 1 LED, no pino 11, e a dois botões, nos pinos 5 e 4:
*Faça com que um dos botões aumente o brilho do LED, e o outro diminua.
*/
const byte LED_1 = 11; //Declaração para o led
const byte BUTTON_mais = 5; //Declaração para o botão que aumentará o brilho
const byte BUTTON_menos = 4; //Declaração para o botão que diminuirá o brilho

void setup() {  
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  pinMode(BUTTON_mais, INPUT);
  pinMode(BUTTON_menos, INPUT);
}

void loop() {
  delay(50);
  static byte aumentar = 0;
  //Fazer o brilho aumentar ou diminuir com base em codições
  if (digitalRead(BUTTON_mais) == true){
      analogWrite(LED_1, aumentar);
      aumentar++;
  }  
  if (digitalRead(BUTTON_menos) == true){
      analogWrite(LED_1, aumentar);
      aumentar--; 
  }
  Serial.println(aumentar);
}
