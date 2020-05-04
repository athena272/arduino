/* ------------SAÍDAS PWM----------------
* O programa fará com que o brilho do LED conectado ao pino 11 aumente gradativamente. 
* O LED no pino 12 foi aceso somente para que você possa comparar visualmente o brilho dos dois…
*-----------------------Exercício 2:-----------------------------------
* Troque as declarações de LED1 e LED2, e observe novamente o comportamento. 
* Anote suas conclusões, e volte o programa para o original.
*/
//---Aqui nós trocamos os valores dos pinos para analisar o que acontece!!!
const byte LED1 = 11;       // pino 12 não possui a função PWM
const byte LED2 = 12;       // pino 11 pode ser usado como PWM

void setup() {
  pinMode ( LED1, OUTPUT ); // configura o pinos 11 e 12 como SAÍDAs
  pinMode ( LED2, OUTPUT );
  digitalWrite ( LED1, 1 ); // acende LED no pino 12, para comparar o brilho
  Serial.begin ( 9600 );
}

void loop() {
  delay (100);               // pausa a execução por 50ms
  static byte n = 0;        // o valor de n controlará o brilho do LED...
  analogWrite( LED2, n );   // configura duty-cycle = n
  Serial.println ( n );     // imprime o valor de n 
  n++;                      // incrementa n
}
