/* ------------Entradas Analógicas--------------
 *  5) Pesquise sobre o LM35 (sensor de temperatura). 
 *   a. Implemente código para imprimir na Serial o valor lido no pino A2 (sensor LM35). 
 *   Ajuste o sensor, no simulador, para dois valores quaisquer de temperatura, 
 *   e anote os valores correspondentes na leitura do pino A2. 
 *   Por exemplo: ajuste para 0ºC e para 100ºC… ou ajuste para -40ºC (mínimo do simulador) 
 *   e +125ºC (máximo do simulador)
 *  
 */
 //--------BIBLIOTECA AUXILIAR--------------
#include "DHT.h"
//----------Declaração Diferente por ser biblioteca------
#define DHTTYPE DHT11 //Informar para biblioteca que estamos usando o modelo dht11
#define DHTPIN A0 //Pino DATA do sensor conectado ao porta Analogica A0

DHT dht(DHTPIN, DHTTYPE);  //Não sei o que significa, (ainda pelo menos!)

void setup() {
  Serial.begin(9600); //Inicializar monitor serial
  Serial.println("DHTxx teste!"); //Uma mensagem bonitinha que só aparece 1 vez
  dht.begin(); //Iniciar o sensor!
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

}
