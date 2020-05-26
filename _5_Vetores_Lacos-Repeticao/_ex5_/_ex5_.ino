//------------Vetores e laços de repetição---------- 
/*
* Implemente agora um comportamento diferente: 
* o sistema deverá CONTAR quantos botões estão 
* pressionados ao mesmo tempo, e acender somente 
* 1 LED, correspondente a essa contagem. 
* Ex: se 3 botões estiverem pressionados 
* (não importa quais botões), somente o LED 3 deverá 
* estar aceso. Se nenhum botão estiver pressionado, 
* nenhum LED estará aceso.
DICA: use laço for para fazer a contagem de 
quantos botões estão pressionados, 
e depois, outro laço for para ativar / desativar os LEDs, 
de acordo com a contagem.
*/
//Declaração Global
byte Leds[3] = {13, 12, 11};
byte Botao [3] = {7, 6, 5};

void setup() {
  byte btnDecla;
  byte ledDecla;

  Serial.begin(9600);
  //------------
  //For declaração Leds
  for(ledDecla = 0; ledDecla <= 2; ledDecla++){
      pinMode(Leds[ledDecla], OUTPUT);
  }
  //For declaração btn
  for(btnDecla = 0; btnDecla <= 2; btnDecla++){
      pinMode(Botao[btnDecla], INPUT);
  }
}

void loop() {
  static byte n_b;
  byte quantos;
  bool estado;
  for(n_b = 0; n_b <= 2; n_b++){
    delay(10);
    bool estado_0 = digitalRead(Botao[0]);
    bool estado_1 = digitalRead(Botao[1]);
    bool estado_2 = digitalRead(Botao[2]);
      if(estado_0 == 0 && estado_1 == 0 && estado_2 == 0){
        quantos = 0;
      }
      if(estado_0 == true && estado_1 == true && estado_2 == true){
        quantos = 3;
      }
      else if((estado_0 == true && estado_1 == true) or (estado_0 == true && estado_2 == true) or (estado_1 == true && estado_2 == true)){
        quantos = 2; 
      }
      else if(estado_0 == true or estado_1 == true or estado_2 == true){
        quantos = 1;
      }
      
      
      Serial.println(quantos);
    switch(quantos){
    case 0:
          //Desligar
            digitalWrite(Leds[0], LOW);
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[2], LOW);
    case 1:
      if(quantos == 1){
            //Ligar
            digitalWrite(Leds[0], HIGH);
            //Desligar
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[2], LOW);
        }
      break;
    case 2:
      if(quantos == 2){
            //Ligar
            digitalWrite(Leds[1], HIGH);
            //Desligar
            digitalWrite(Leds[0], LOW);
            digitalWrite(Leds[2], LOW);
        }
      break;
  case 3:
      if(quantos == 3){
            //Ligar
            digitalWrite(Leds[2], HIGH);
            //Desligar
            digitalWrite(Leds[0], LOW);
            digitalWrite(Leds[1], LOW);
        }
      break;
    
  }
  }
  
  
       
}
