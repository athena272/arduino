/* ------------Entradas Analógicas--------------
 *  3) Considere agora 3 LEDs: faça com que cada LED acenda de acordo com a tabela abaixo:
valor do potenciômetro | LED aceso
      0 a 341          |      1
      342 a 682        |      2
      683 a 1023       |      3
*/

const byte Potenciometro = A0; //Declara a porta A0 
byte LED_1 = 13; //Declara a variavel com valor 13;
byte LED_2 = 12; //Declara a variavel com valor 12;
byte LED_3 = 11; //Declara a variavel com valor 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_1, OUTPUT); //configura pino 13 como saída
  pinMode(LED_2, OUTPUT); //configura pino 12 como saída
  pinMode(LED_3, OUTPUT); //configura pino 11 como saída
  Serial.begin(9600); //Inicia monitor serial para visualizar os dados
}
void loop() {
  delay(250); //Intervalo para os dados serem melhores processados
  // put your main code here, to run repeatedly:
  int valor_POT = analogRead(Potenciometro);
  Serial.println(valor_POT); //Imprimir valor recebi pela Porta A0 no monitor serial
  if(valor_POT <= 341){  
    digitalWrite(LED_1, HIGH);
  }
  else {
    digitalWrite(LED_1, LOW);
  }
  if (valor_POT >= 342 && valor_POT <= 682){
    digitalWrite(LED_2, HIGH);
  }
  else{
    digitalWrite(LED_2, LOW);
  }
  if (valor_POT >= 683){
    digitalWrite(LED_3, HIGH);
  }
  else{
    digitalWrite(LED_3, LOW);
  }
}
