
// Declarações Globais
const byte LED1   = 13;           // declara constante LED1   = 13
const byte BOTAO1 =  5;           // declara constante BOTAO1 =  5

void setup() {
  pinMode ( LED1, OUTPUT );       // configura pino 13 como SAÍDA
  pinMode ( BOTAO1, INPUT );      // configura pino  5 como ENTRADA
  Serial.begin( 9600 );           // inicializa comunicação serial a 9600 bits/s
}

void loop() {
  delay (10);                     // somente para o simulador
  
  static bool acao_executada = 0; // flag

                                  // o algoritmo começa aqui:
  bool bt = digitalRead(BOTAO1);  // leia o estado do botão
  if ( bt == true ) {                // se o botão está pressionado,
    if ( acao_executada == 0 ) {  //   se ação ainda não foi executada,
                                  //     inverta o LED
      digitalWrite (LED1, ! digitalRead(LED1));
      acao_executada = 1;         //     memorize que a ação já foi executada
    }
  }
  else {                          //   caso contrário (botão liberado),
    acao_executada = 0;           //     libere a flag, para o próximo pulso
  }
}
