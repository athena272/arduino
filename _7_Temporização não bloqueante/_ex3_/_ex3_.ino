byte btn = 5;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(btn, INPUT);
}

void loop() {
     if(Resultado() == 0){
        Serial.println("0 - nenhum evento detectado no botão");
     }
     else if(Resultado() == 1){
        Serial.println("1 - pulso curto detectado");
     }
     else if(Resultado() == 2){
        Serial.println("2 - pulso longo detectado");
     }

}
byte Resultado(){
static byte estado = 0;
static unsigned long t0 = 0;
unsigned long ta = millis();
bool b = digitalRead(btn);
switch (estado) {
  case 0:
    if (b == 1) {
      t0 = ta;
      estado = 1;
    }
  break;

  case 1:
    if (b == 0) {
      estado = 0;
    }

    else if (ta - t0 >= 2000) {
      estado = 2;
    }
  break;

  case 2:
    if (b == 0) {
      estado = 0;
    }
  break;
}
  return estado;
}
