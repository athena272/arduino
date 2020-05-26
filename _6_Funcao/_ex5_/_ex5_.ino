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
      Serial.println(s_b);

  } 
    switch(s_b){
        case 0:
          if(s_b == 0){
            //ligar 
            inverteLED(Leds[0]);
            //Desligar
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[2], LOW);
          }
          break;
        case 1:
           if(s_b == 1){
           //ligar 
            inverteLED(Leds[1]);
            //Desligar
            digitalWrite(Leds[0], LOW);
            digitalWrite(Leds[2], LOW);
          }
          break;
        
        case 2:
           if(s_b == 2){
            //ligar
            inverteLED(Leds[2]);
            //Desligar
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[0], LOW);
          }
          break;
    }

}
//Declaração de função
void inverteLED(byte pinoLED){
      digitalWrite(pinoLED, ! digitalRead(pinoLED));
 }
