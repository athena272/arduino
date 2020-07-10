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
const byte led[8] = {13, 12, 11, 10, 9, 8, 7, 6};

void setup() {    
    Serial.begin(9600); // Iniciar Monitor Serial
    //Declaracao de 8 pinos com "for";
    byte pinDeclaracao;
    for(pinDeclaracao = 0; pinDeclaracao <= 7; pinDeclaracao++){
        pinMode(led[pinDeclaracao], OUTPUT);
      }
}
void loop() {
   //Receita de bolo para receber dados no monitor 
  char M_acende; 
  if ( Serial.available() > 0 ){ 
  M_acende = Serial.read(); //Variavel que vai receber dados do monitor serial
  //-------------------------PRINTS-----------------------------------     
  Serial.println(M_acende); //Imprimir o que foi digitado
  }
  
  //Fim Receita de Bolo
  //------------------------------------------
  //Acender LEDS com maiúsculas
  for(char i = 'A'; i <= 'H'; i++){ //Loop com base nas letras Maisculas
    for(byte posled = 0; posled <= 7; posled++){ //Posição dos leds em relação a letra correspondente 
        if(i == M_acende && (i - 'A') == posled){
          digitalWrite(led[posled], HIGH);
          Serial.print(i); //Imprimir a variavel "i" do loop
          Serial.print('|');
          Serial.println(posled); //Imprimir a pos do led que será aceso
          Serial.println("---------");
        }
    }
  }
  //Apagar Leds com minusculas
  for(char j = 'a'; j <= 'h'; j++){
    for(byte posled = 0; posled <= 7; posled++){
        if(j == M_acende && (j - 'a') == posled){
          digitalWrite(led[posled], LOW);
          Serial.print(j); //Imprimir a variavel j do loop
          Serial.print('|');
          Serial.println(posled); //Imprimir pos do led que irá apagar
          Serial.println("---------");
        }
    }
  }
  
}
