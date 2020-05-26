const byte LED_1 = 13;
void inverteLED();
void setup() {
  pinMode ( LED_1, OUTPUT );
}

void loop() {
  inverteLED(); //Chamando a nova função que irá inverter o Led
}



// declara função piscaLED
void inverteLED() {
    digitalWrite(LED_1, ! digitalRead(LED_1));
    delay(500);
    digitalWrite(LED_1, ! ! digitalRead(LED_1));
    delay(500);
}
