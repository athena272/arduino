//--------Vetores e Laços de Repetição------
/*
6. No exercício 3 da seção Entradas Analógicas, 
fizemos com que o giro do potenciômetro, de 0 a 100%, 
fosse dividido em 3 intervalos, cada intervalo 
correspondendo a um, dentre 3 LEDs. Use o conceito 
de vetores para fazer o mesmo, para todos os 8 LEDs. 
DICA: siga o algoritmo abaixo:

faça: pot = valor analógico do potenciômetro
 para i variando de 0 a 7, repita:
    se i igual a pot / 128
      acenda LED[i]
    caso contrário
      apague LED[i]

*/
const byte Potenciometro = A0;
const byte Leds[8] = {13, 12, 11, 10, 9, 8, 7, 6}; 
void setup() {
  byte pinDecla;
  Serial.begin(9600);
  //Declaracao de Leds
  for(pinDecla = 0; pinDecla <= 7; pinDecla++){
      pinMode(Leds[pinDecla], OUTPUT);
  }   
}

void loop() {
  int pot = analogRead(Potenciometro);
  Serial.println(pot);
  for(byte i = 0; i <= 7; i++){
      if(i == (pot / 128)){
        digitalWrite(Leds[i], HIGH);
      } 
      else{
        digitalWrite(Leds[i], LOW);
     }
 }

}
