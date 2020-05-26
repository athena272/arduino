//Variáveis Globais
const byte Leds[3] = {13, 12, 11};
const byte Botao[4] = {7, 6, 5, 4};
void setup() {
  Serial.begin(9600);
  //Declaraçao leds
  byte led;
  for(led =0; led <= 2; led++){
    pinMode(Leds[led], OUTPUT);
  }
  //Declaração botão
  byte b;
  for(b = 0; b <= 1; b++){
    pinMode(Botao[b], INPUT);
  }
  
}

void loop() {
  byte i;
  static byte s_b = 0;
  
  static int piscar_tempo = 0;
  //BOTOES CONTROLADORES DE TEMPO
  bool btn2 = digitalRead(Botao[2]);
  bool btn3 = digitalRead(Botao[3]);
  for(i = 0; i <= 1; i++){
    delay(50);
    if(digitalRead(Botao[0]) == true)
      if(s_b == 0){
          s_b = 2;
      }
      else{
          s_b -= 1;   
      }
    
    if(digitalRead(Botao[1]) == true)
      if(s_b == 2){
        s_b = 0;
      }
      else{
        s_b += 1;
      }
      Serial.print("BOTÂO: ");
      Serial.print(s_b);
      Serial.print(" | ");
      Serial.print("Velocidade: ");
      Serial.println(piscar_tempo);
  } 
    switch(s_b){
        case 0:
          if(s_b == 0){
            //ligar com base no controle de tempo dos botões
            if(btn2 == true){
                piscar_tempo += 1;
            }
            if(btn3 == true){
              piscar_tempo -= 1;
            }
            piscarLed(Leds[0], piscar_tempo);
            //Desligar
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[2], LOW);
          }
          break;
        case 1:
           if(s_b == 1){
           //ligar com base no controle de tempo dos botões
            if(btn2 == true){
               piscar_tempo += 1;
            }
            if(btn3 == true){
              piscar_tempo -= 1;
            }
            piscarLed(Leds[1], piscar_tempo);
            //Desligar
            digitalWrite(Leds[0], LOW);
            digitalWrite(Leds[2], LOW);
          }
          break;
        
        case 2:
           if(s_b == 2){
            //ligar com base no controle de tempo dos botões
            if(btn2 == true){
              piscar_tempo += 1;
              piscarLed(Leds[2], piscar_tempo);
            }
            if(btn3 == true){
              piscar_tempo -= 1;  
            }
            piscarLed(Leds[2], piscar_tempo);
            //Desligar
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[0], LOW);
          }
          break;
    }

}
//Declaração de função
void piscarLed(byte pinoLED, int tempo){
      digitalWrite(pinoLED, HIGH);
      delay(tempo);
      digitalWrite(pinoLED, LOW);
      delay(tempo);
 }
