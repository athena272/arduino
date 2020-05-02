/* ------------Entradas Analógicas--------------
* 4) Considere 1 LED e duas entradas analógicas (potenciômetro e LDR). 
* Faça com que o LED acenda quando o valor do LDR for menor que o valor do potenciômetro.
*  
*/
const byte Potenciometro = A0; //Declara porta digital A0 para o potenciometro
const int LDR = A1; //Declara porta digital A1 para o "Light Dependent Resitor"
byte LED_1 = 13; //Declara a variável com valor 13
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_1, OUTPUT); //Configurar o pino 13 como saída
  Serial.begin(9600); //Iniciar o Monitor serial, para visualizar dados
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(250);
  int valor_POT = analogRead(Potenciometro);
  int valor_LDR = analogRead(LDR);
  if (valor_LDR < valor_POT){
    digitalWrite(LED_1, HIGH);
    Serial.print("Valor_LDR = ");
    Serial.print(valor_LDR);
    Serial.print(" < ");
    Serial.print("Valor_POT = ");
    Serial.println(valor_POT);
    Serial.println("_______________________");
  }
 else{
    digitalWrite(LED_1, LOW);
    Serial.print("Valor_LDR = ");
    Serial.print(valor_LDR);
    Serial.print(" > ");
    Serial.print("Valor_POT = ");
    Serial.println(valor_POT);
    Serial.println("_______________________");
 }
}
