/* ------------SAÍDAS PWM----------------
* O programa fará com que o brilho do LED conectado ao pino 11 aumente gradativamente. 
* O LED no pino 12 foi aceso somente para que você possa comparar visualmente o brilho dos dois…
-----------------------Exercício 1:-----------------------------------
* No simulador, conecte um osciloscópio para visualizar o sinal no pino 11, 
* e observe a relação entre a forma de onda no osciloscópio, 
* o brilho do LED e o valor de n, no monitor Serial.
*/
const byte LED1 = 12;       // pino 12 não possui a função PWM
const byte LED2 = 11;       // pino 11 pode ser usado como PWM

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
