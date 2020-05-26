const byte LED[1] = {13};
const byte BTN[1] = {5};
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  //Declaração LED
  byte led;
  for(led = 0; led < 1; led++){
     pinMode(LED[led], OUTPUT);
  }
  //Declaração Botão
  byte btn;
  for(btn = 0; btn < 1; btn++){
      pinMode(BTN[btn], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(95);

  if(pulsoNoBotao() == 1){
    inverteLED();
    }
  else{
    digitalWrite(LED[0], LOW);
    }
  //Estados do BOTAO e LED
  Serial.print("LED: ");
  Serial.print(inverteLED());
  Serial.print(" | ");
  Serial.print("BOTÃO: ");
  Serial.println(pulsoNoBotao());
}
//Declaração função InverteLED
bool inverteLED(){
  byte led_i;
  for(led_i = 0; led_i < 1; led_i++) {
      digitalWrite(LED[led_i], ! digitalRead(LED[led_i]));
  }
  
  
}
//Declaração de função pulso no botão
bool pulsoNoBotao(){
     byte btn_i;
     for(btn_i = 0; btn_i < 1; btn_i++){
     bool pulso = 0;
     delay(10);
     bool estado = digitalRead(BTN[btn_i]);
      switch(estado){ 
          case 0:
             if(estado == false){
                pulso = 0;
               }
         case 1:
              if(estado == true){  
                pulso = 1;
                
              }
     }
     return pulso;
     }
  }
