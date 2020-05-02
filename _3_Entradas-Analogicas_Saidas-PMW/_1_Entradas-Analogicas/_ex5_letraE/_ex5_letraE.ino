/* ------------Entradas Analógicas--------------
 *  5) Pesquise sobre o LM35 (sensor de temperatura). 
 *   d. Faça com que o LED acenda somente quando a temperatura for maior que 60ºC
 *  
 */
 //--------BIBLIOTECA AUXILIAR--------------
#include "DHT.h"
//----------Declaração Diferente por ser biblioteca------
#define DHTTYPE DHT11 //Informar para biblioteca que estamos usando o modelo dht11
#define DHTPIN A0 //Pino DATA do sensor conectado ao porta Analogica A0

DHT dht(DHTPIN, DHTTYPE);  //Não sei o que significa, (ainda pelo menos!)
//Declaração padrão para o LED
byte LED_1 = 13;
void setup() {
  Serial.begin(9600); //Inicializar monitor serial
  Serial.println("DHTxx teste!"); //Uma mensagem bonitinha que só aparece 1 vez
  dht.begin(); //Iniciar o sensor!
  pinMode(LED_1, OUTPUT);
} 

void loop() {
  //Não diminuir o valor abaixo. O ideal é a leitura a cada 2 segundos
  delay(2500); //coloquei um pouco mais, só por PARANÓIA minha, podem deixar só com 2000 mesmo;
  //------------------------------------------------------------------
  
  float C = dht.readTemperature();//Função da biblioteca para fazer a leitura da temperatura, que será armazenada na variável "t"
  //-------PRINT do RESULTADO---------------
  Serial.print("Temperatura = ");
  Serial.print(C); 
  Serial.println("°C(Celsius)");
  if(C >= 27.50){ //Coloquei 27.5 no lugar de 60, porque assim, o LED nunca ia acender
    digitalWrite(LED_1, HIGH);
  }
  else{
    digitalWrite(LED_1, LOW);
  }
}
