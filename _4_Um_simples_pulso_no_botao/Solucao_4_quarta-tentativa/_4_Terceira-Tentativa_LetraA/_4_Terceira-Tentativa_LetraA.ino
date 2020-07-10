//----------Solução 4--------------
/*

pelo valor do estado, selecione:
  caso estado seja 0:
    se botão pressionado
      inverta o LED
      faça estado = 1
  caso estado seja 1:
    se botão não pressionado
      faça estado = 0

---------------------------------------
Leia sobre a estrutura de controle 
switch / case e implemente o código 
para a MEF descrita acima.
*/


// Declarações Globais
const byte LED_1   = 13;           // declara constante LED1   = 13
const byte BOTAO_1 =  5;           // declara constante BOTAO1 =  5

void setup() {
  pinMode ( LED_1, OUTPUT );       // configura pino 13 como SAÍDA
  pinMode ( BOTAO_1, INPUT );      // configura pino  5 como ENTRADA
  Serial.begin( 9600 );           // inicializa comunicação serial a 9600 bits/s
}

void loop() {
  bool bt = digitalRead(BOTAO_1);
  static bool estado_futuro = 0;    
  
  delay(10);
  
  switch(estado_futuro){
    case 0:
      if (bt == 1 && estado_futuro == 0){
          digitalWrite(LED_1, ! digitalRead(LED_1));
          estado_futuro = 1;
      }
      break;
    case 1:
      if(bt == 0 && estado_futuro == 1){
        estado_futuro = 0;
      }   
      break;
  }
  Serial.print(bt);
  Serial.println(estado_futuro);
}  
