/* ------------Entradas Analógicas--------------
 *  5) Pesquise sobre o LM35 (sensor de temperatura). 
 *   d. Pesquise sobre como converter a temperatura de ºC para ºF, 
 *   e implemente código para imprimir 
 *   na Serial o valor da temperatura, em ºC e ºF.

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
  
  float C = dht.readTemperature();//Função da biblioteca para fazer a leitura da temperatura, que será armazenada na variável "t"
  //Está função ao colocar o true, transforma a temperatura em Fahrenheit, mas você pode usar a formula também
  float F = dht.readTemperature(true);//Função da biblioteca para fazer a leitura da temperatura, que será armazenada na variável "f"
  
  float valor_mapeado = map(C, 0, 100, 0, 40); //Converter a temperatura em valor proporcional dentro do range definido

  float formula_conversao_C_to_F = (C * 9/5) + 32;
  
  //-------PRINT dos RESULTADOS---------------
  Serial.print("Temperatura = ");
  Serial.print(C); 
  Serial.println("°C(Celsius)");
  Serial.print("Temperatura = ");
  Serial.print(F);
  Serial.print("°F(Fahrenheit) == ");
  Serial.print("Pela Formula = ");
  Serial.print(formula_conversao_C_to_F);
  Serial.println("°F");
  Serial.println("--------------------------------"); //Uma divisão dos dados a cada loop

}
