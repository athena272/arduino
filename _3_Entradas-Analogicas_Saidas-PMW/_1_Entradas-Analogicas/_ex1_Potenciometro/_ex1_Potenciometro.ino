/* ------------Entradas Analógicas--------------
 *  1) Execute esse código, gire o potenciômetro, 
 *  e observe o resultado no monitor Serial: 
 *  Qual o valor máximo? 
 *  Qual o valor mínimo?
 */
 
const byte Potenciometro = A0; // Potenciômetro conectado à entrada Analógica 0

                              // OBS: Entradas Analógicas não precisam do pinMode
void setup() {
  Serial.begin(9600); //Inicia o monitor Serial
}

void loop() {
  delay(100);
  int valor_potenmetro = analogRead(Potenciometro);
  Serial.println(valor_potenmetro);

}
