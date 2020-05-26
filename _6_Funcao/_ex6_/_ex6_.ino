const byte LED_1 = 13;
const byte BTN = 5;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED_1, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(115);

  if(pulsoNoBotao() == 1){
      digitalWrite(LED_1, ! digitalRead(LED_1));

    }
    
}
//Declaração de função
bool pulsoNoBotao(){
     bool pulso = 0;
     bool estado = digitalRead(BTN);
      switch(estado){ 
          case 0:
             if(estado == false){
                estado = 0;
               }
         case 1:
              if(estado == true){
                estado = 1;  
                pulso = 1;
                
              }
     }
     return pulso;
     
  }
