const byte btn[4] = {7, 6, 5, 4};
const byte S[4] = {13, 12, 11, 10};
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  //Declaração BOTAO
  byte declaB;
  for(declaB = 0; declaB <= 3; declaB++){ 
  }
   pinMode(btn[declaB], INPUT);
  //Declaração LED
  byte declaL; 
  for(declaL = 0; declaL <= 3; declaL++){
      pinMode(S[declaL], OUTPUT);
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
    byte i;
    for(i = 0; i <= 3; i++){
    byte estado[4] = {0, 1, 2, 3};
    static unsigned long t0 = 0;
    unsigned long ta = millis();
    bool b = digitalRead(btn[i]);
    
    switch (estado[i]) {
      case 0:
        if (b == 1) {
          t0 = ta;
          estado[i] = 1;
        }
      break;
    
      case 1:
        if (b == 0) {
          digitalWrite (S[i], HIGH);
          estado[i] = 0;
        }
    
        else if (ta - t0 >= 2000) {
          digitalWrite (S[i], LOW);
          estado[i] = 2;
        }
      break;
    
      case 2:
        if (b == 0) {
          estado[i] = 0;
        }
      break;
    }
      Serial.println(estado[i]);
    }
}
    
 
