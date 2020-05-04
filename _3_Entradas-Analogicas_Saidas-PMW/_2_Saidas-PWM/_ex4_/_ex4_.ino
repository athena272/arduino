/* ------------SAÍDAS PWM----------------
Além do pino 11, quais outros pinos do Arduino Uno possuem a função PWM?

-----------------------Exercício 4 A e B:-----------------------------------
*-- Controle o brilho de outro LED, usando agora a leitura do potenciômetro

*
*--A função analogRead() retorna valores de 0 a 1023, mas a função analogWrite() recebe valores de 0 a 255. 
*Compatibilize as duas, para que 100% no potenciômetro corresponda a 100% no LED.
*/
const byte LED_1 = 6; //Informa que o pino PWM será o "6"

const byte Potenciometro = A0; //Declara a porta analogica A0 para o POTENCIOMETRO

void setup() {
  Serial.begin(9600); //Inicar Monitor Serial
  pinMode(LED_1, OUTPUT); // Declara o pino PWM 6 como Saída
} 

void loop() {
  delay(50);
  int valor_POT = analogRead(Potenciometro); //Ler o valor do estado do Potenciometro
  /*---------------------------------
  --Usar a função map para deixar os valores proporcionais(Do LED e do Potenciometro)*/
  byte valor_LED = map(valor_POT, 0, 1023, 0, 255);
  /*--------------------------------
  --Vamos acerder o LED */
  analogWrite(LED_1, valor_LED); //Acendendo LED
  //Vamos agora printar tantos os valores proporcionais (0 à 1023) para (0 à 255)
  Serial.print("Valor LED = ");
  Serial.print(valor_LED);
  Serial.print(" | ");
  Serial.print("Valor POT = ");
  Serial.println(valor_POT);
}
