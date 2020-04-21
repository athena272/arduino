/*-----------AUTOR: GUILHERME R. ALVES--------------------
 * Criando um LED que pisca
 * ----Vamos lá!!!!!!!!!!
 * Mais conhecido também como exemplo "BLINK"
 */
 //Declarar variável LED como valor 13
int LED = 13;
void setup() {
  //Definir a porta 13 como saíde de energia para alimentar o LED com 5 Volts
  pinMode(LED, OUTPUT);
}

void loop() {
  //Fazer LED acender, estado Ligado, ou seja, HIG
  digitalWrite(LED, HIGH);
  delay(2000); //Ficar aceso por 2 segundos
  //Apagar o LED, estado desligado, ou seja, LOW
  digitalWrite(LED, LOW);
  delay(2000);//Ficar desligado por 2 segundos
}
