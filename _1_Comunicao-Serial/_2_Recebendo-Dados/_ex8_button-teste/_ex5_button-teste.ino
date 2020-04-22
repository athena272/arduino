/*---AUTOR: Guilherme R. Alves------------------------
 * Teste Botão sendo pressionado
 * Mensagem para aparecer no monitor serial;
 * caso o botão seja pressionado
 * 
 */
 int ButtonStephanie = 10;
void setup() {
  //Iniciar monitor Serial
  Serial.begin(9600);
  pinMode(ButtonStephanie, INPUT);
}

void loop() {
  if (digitalRead(ButtonStephanie) == HIGH) {
      Serial.println("STEPHANIE LINDA!;");
    }
  else{
      Serial.println("Erro404(NotFound), aperto o botão. AGORA!!!;");
    }
  delay(1500);
}
