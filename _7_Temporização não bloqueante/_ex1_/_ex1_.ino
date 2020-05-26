byte btn = 5;
byte S = 13;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(S, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
static byte estado = 0;
static unsigned long t0 = 0;
unsigned long ta = millis();
bool b = digitalRead(btn);
Serial.println(estado);
switch (estado) {
  case 0:
    if (b == 1) {
      t0 = ta;
      estado = 1;
    }
  break;

  case 1:
    if (b == 0) {
      digitalWrite (S, HIGH);
      estado = 0;
    }

    else if (ta - t0 >= 2000) {
      digitalWrite (S, LOW);
      estado = 2;
    }
  break;

  case 2:
    if (b == 0) {
      estado = 0;
    }
  break;
}

}
