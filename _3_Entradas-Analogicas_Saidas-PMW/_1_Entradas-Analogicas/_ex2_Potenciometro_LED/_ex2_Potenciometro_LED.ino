/* ------------Entradas Analógicas--------------
 *  2)Considere 1 LED no pino 13. 
 *  Faça com que esse LED acenda quando o valor do potenciômetro for maior que 50%, 
 *  e apague caso contrário.
 *  
 */
 
const byte Potenciometro = A0; // Potenciômetro conectado à entrada Analógica 0
byte LED_1 = 13;
                              // OBS: Entradas Analógicas não precisam do pinMode
void setup() {
  Serial.begin(9600); //Inicia o monitor Serial
  pinMode(LED_1, OUTPUT);
}

void loop() {
  delay(100); //Tempo para os dados serem processados mais facilmente
  int valor_potenmetro = analogRead(Potenciometro); //Leitura do valor potenciomentro armazenado na variável
  int metade_valor = 1023 / 2; //Encontrar 50% do valor lido pelo arduino
  if(valor_potenmetro > metade_valor){ //Se for maior que 50% então...
    digitalWrite(LED_1, HIGH); //Liga o LED
    //----TABELINHA DOS VALORES DO POTENCIOMETRO-----
    //Fazer uma tabela visualmente bonita
    Serial.print(valor_potenmetro);
    Serial.print(" > ");
    Serial.println(metade_valor);  
  }
  else{ //Senão ...
    digitalWrite(LED_1, LOW); //Desliga o LED
    //----TABELINHA DOS VALORES DO POTENCIOMETRO-----
    //Fazer uma tabela visualmente bonita
    Serial.print(valor_potenmetro);
    Serial.print(" < ");
    Serial.println(metade_valor); 
 }
 
}
