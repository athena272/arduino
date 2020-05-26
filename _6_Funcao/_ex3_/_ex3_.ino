const byte Leds[3] = {7, 6, 5};
const byte potenciometro = A0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  byte pinL;
  for(pinL = 0; pinL <= 2; pinL++){
    pinMode(Leds[pinL], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot = analogRead(potenciometro);
  byte i;
  for(i = 0; i <= 2; i++){
    delay(10);
     if(i == pot / 342  ){
        piscaLED(Leds[i], 1000);
     }
     else{
       digitalWrite(Leds[i], LOW);
      }
     
  }
}
//Função para piscar
void piscaLED(byte LED, int tempo){
      digitalWrite(LED, ! digitalRead(LED));
      delay(tempo);
      digitalWrite(LED, ! ! digitalRead(LED));
      delay(tempo);
  
  }
