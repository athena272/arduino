void setup() {
  Serial.begin(9600);
  }
void loop() {
   byte a = 20;

  byte b = map(a, 0, 50, 0, 5);

  Serial.print("a = ");
  Serial.print(a);
  Serial.print(" b = ");
  Serial.println(b);
  delay(10000);
}
