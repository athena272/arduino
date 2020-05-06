
// Declarações Globais
const byte LED1   = 13;           // declara constante LED1   = 13
const byte BOTAO1 =  5;           // declara constante BOTAO1 =  5

void setup() {
  pinMode ( LED1, OUTPUT );       // configura pino 13 como SAÍDA
  pinMode ( BOTAO1, INPUT );      // configura pino  5 como ENTRADA
  Serial.begin( 9600 );           // inicializa comunicação serial a 9600 bits/s
}

void loop() {
  delay (50);                   // <- pausa bem grande para vermos o que acontece
                                  // o algoritmo começa aqui:   
  bool bt = digitalRead(BOTAO1);  // lê BOTAO1
  if ( bt == true ) {               // se o botão está pressionado,
                                 //   inverta o LED1
    digitalWrite (LED1, ! digitalRead(LED1));
  }
}
