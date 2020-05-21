
// Declarações Globais
const byte LED_1   = 13;           // declara constante LED1   = 13
const byte BOTAO_1 =  5;           // declara constante BOTAO1 =  5

void setup() {
  pinMode ( LED_1, OUTPUT );       // configura pino 13 como SAÍDA
  pinMode ( BOTAO_1, INPUT );      // configura pino  5 como ENTRADA
  Serial.begin( 9600 );           // inicializa comunicação serial a 9600 bits/s
}

void loop() {
  delay (250);                     // somente para o simulador

  bool botao_atual = digitalRead(BOTAO_1);
  static bool botao_anterior = 0;
  if (botao_atual == 1 && botao_anterior == 0){
      digitalWrite(LED_1, HIGH);
     
  }
  botao_anterior = botao_atual;
  


  Serial.println(botao_anterior);
 
 
} 
