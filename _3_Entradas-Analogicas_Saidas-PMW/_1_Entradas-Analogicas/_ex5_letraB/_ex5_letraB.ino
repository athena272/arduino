/* ------------Entradas Analógicas--------------
 *  5) Pesquise sobre o LM35 (sensor de temperatura). 
 *   b. Leia sobre a função map(), e use-a para converter o valor lido no pino analógico 
 *   para o valor correspondente em ºC, 
 *   de acordo com suas medições feitas no item anterior
 *  
 */
 //Acabei usando o sensor DHT11, e não o LM35
 //--------BIBLIOTECA AUXILIAR--------------
#include "DHT.h"
//----------Declaração Diferente por ser biblioteca------
#define DHTTYPE DHT11 //Informar para biblioteca que estamos usando o modelo dht11
#define DHTPIN A0 //Pino DATA do sensor conectado ao porta Analogica A0

DHT dht(DHTPIN, DHTTYPE); //Não sei o que significa, (ainda pelo menos!)

void setup() {
  Serial.begin(9600); //Inicializar o monitor serial
  Serial.println("DHTxx teste!"); //Uma mensagem bonitinha que só aparece 1 vez
  dht.begin(); //inicializar o sensor
} 

void loop() {
  //Não diminuir o valor abaixo. O ideal é a leitura a cada 2 segundos
  delay(2000);
  //------------------------------------------------------------------
  
  float t = dht.readTemperature();//Função da biblioteca para fazer a leitura da temperatura, que será armazenada na variável "t"
  float valor_mapeado = map(t, 0, 100, 0, 40); //Converter a temperatura em valor proporcional dentro do range definido
  //-------PRINT dos RESULTADOS---------------
  Serial.print("Temperatura = ");
  Serial.print(t); 
  Serial.println("°C(Celsius)");
  Serial.print("Testando função map(). Resultado = ");
  Serial.println(valor_mapeado);
  Serial.println("--------------------------------"); //Uma divisão dos dados a cada loop

}
