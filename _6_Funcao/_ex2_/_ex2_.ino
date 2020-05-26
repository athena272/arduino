const int pot = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  delay(10);
  int valor_t = analogRead(pot);
  piscaLED(13, valor_t);
  Serial.println(valor_t);
}  
void piscaLED(byte pinoLED, int tempo) {
  digitalWrite(pinoLED, ! digitalRead(pinoLED));
  delay(tempo);
  digitalWrite(pinoLED, ! ! digitalRead(pinoLED));
  delay(tempo);

}
