/*--------------Veotres e laços de Repetição------------------
*
*4) Volte ao exercício 4 da seção Entradas e Saídas Digitais. 
*Use vetores e laços de repetição para fazer com 
*que os LEDs de 0 a 7 sejam controlados 
*por caracteres recebidos pela Serial:  
*o LED[0] acende ao receber o caractere ‘A’, 
*e apaga quando receber o caractere ‘a’, 
*o LED[1] acende ao receber o caractere ‘B’, 
*e apaga quando receber o caractere ‘b’, 
*e assim por diante. 
*DICA: caracteres são números… logo, 
*é possível calcular, por exemplo, que ‘a’ + 1 = ‘b’.
*/

//Declaração de variávies globais
const byte Leds[8] = {13, 12, 11, 10, 9, 8, 7, 6};

void setup() {    
    Serial.begin(9600); // Iniciar Monitor Serial
    //Declaracao de 8 pinos com "for";
    byte pinDeclaracao;
    for(pinDeclaracao = 0; pinDeclaracao <= 7; pinDeclaracao++){
        pinMode(Leds[pinDeclaracao], OUTPUT);
      }
}
void loop() {
    
  char Maiusculas_acende; 
  
  
  delay(100);
  if ( Serial.available() > 0 ){ 
  Maiusculas_acende = Serial.read(); 
  //-------------------------PRINTS-----------------------------------
  Serial.println(Maiusculas_acende);   
  }
  
  byte Conversao_ASCII = Maiusculas_acende;

  //------------------------------------------
  byte posicaoLed;
  for(posicaoLed = 0; posicaoLed <= 7; posicaoLed++){
    
      switch(posicaoLed){
             
        case 0:
              if(Conversao_ASCII == 'A'){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == 'a'){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
        case 1:
              if(Conversao_ASCII == ('A' + 1)){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == ('a' + 1)){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
       case 2:
              if(Conversao_ASCII == ('A' + 2)){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == ('a' + 2)){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
       case 3:
              if(Conversao_ASCII == ('A' + 3)){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == ('a' + 3)){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
       case 4:
              if(Conversao_ASCII == ('A' + 4)){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == ('a' + 4)){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
        case 5:
              if(Conversao_ASCII == ('A' + 5)){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == ('a' + 5)){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
        case 6:
              if(Conversao_ASCII == ('A' + 6)){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == ('a' + 6)){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
        case 7:
              if(Conversao_ASCII == ('A' + 7)){
                 digitalWrite(Leds[posicaoLed], HIGH);  
              }
              else if (Conversao_ASCII == ('a' + 7)){
                 digitalWrite(Leds[posicaoLed], LOW);
              }          
              break;
      }


     
  }

}
