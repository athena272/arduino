//------Vetores e Laços--------------
const byte Leds[3] = {13, 12, 11};
const byte Botao[2] = {7, 6};
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
  for(i = 0; i <= 1; i++){
    delay(115);
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
      Serial.println(s_b);
  } 
    switch(s_b){
        case 0:
          if(s_b == 0){
            //ligar
            digitalWrite(Leds[0], HIGH);
            //Desligar
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[2], LOW);
          }
          break;
        case 1:
           if(s_b == 1){
            //ligar
            digitalWrite(Leds[1], HIGH);
            //Desligar
            digitalWrite(Leds[0], LOW);
            digitalWrite(Leds[2], LOW);
          }
          break;
        
        case 2:
           if(s_b == 2){
            //ligar
            digitalWrite(Leds[2], HIGH);
            //Desligar
            digitalWrite(Leds[1], LOW);
            digitalWrite(Leds[0], LOW);
          }
          break;
    }

}
