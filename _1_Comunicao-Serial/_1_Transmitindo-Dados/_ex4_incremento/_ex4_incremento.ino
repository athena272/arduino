/*---------AUTOR: Guilherme R. Alves----------
 * Incremento
 * 
 */
 int x = 2;
 int y;
void setup() {
  //Iniciar monitor serial para visualizar os dados
  Serial.begin(9600);
 
}

void loop() {
 //Realizando Incremento
  y = x++;
  //Visualizar o incremento nas duas variáveis
  Serial.println(y);
  Serial.println(x);
  Serial.println("------------");
}
