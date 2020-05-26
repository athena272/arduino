//----------Vetores--------------
/*
1.
// ao invés de declarar cada LED, individualmente...
// const byte LED1 = 13;
// const byte LED2 = 12;
// const byte LED3 = 13;
// const byte LED4 = 10;

// podemos declarar um vetor, com os pinos de 4 LEDs
const byte LED[] = {13, 12, 11, 10};
------------------------------------
Considere o exemplo acima, 
e faça o mesmo para a declaração dos botões
*/


// Declarações Globais
byte pinLEDS[4] = {13, 12, 11, 10};
byte btn[4] = {5, 4, 3, 2};

void setup() {
  byte pinDecla;
  byte btnDecla;
  
  for(pinDecla = 0; pinDecla <= 3; pinDecla++){
    pinMode(pinLEDS[pinDecla], OUTPUT);
  }
  for(btnDecla = 0; btnDecla <= 3; btnDecla++){
    pinMode(btn[btnDecla], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
    static byte qual_estado;

    
    for(qual_estado = 0; qual_estado <= 3; qual_estado++){
      bool leitura = digitalRead(btn[qual_estado]);
      
    
      static byte flag_0 = 0; // flag
      static byte flag_1 = 0; // flag
      static byte flag_2 = 0; // flag
      static byte flag_3 = 0; // flag
      
     
      switch(qual_estado){
        case 0:
          if(leitura == true){
            if (flag_0 == 0){
              digitalWrite(pinLEDS[qual_estado], ! digitalRead(pinLEDS[qual_estado]));
              flag_0 = 1;
              
            }
          }
          else{
            flag_0 = 0;
            }
              break;
      case 1:
      if(leitura == true){
            if (flag_1 == 0){
              digitalWrite(pinLEDS[qual_estado], ! digitalRead(pinLEDS[qual_estado]));
              flag_1 = 1;
              
            }
          }
          else{
            flag_1 = 0;
            }
              break;
        case 2:
          if(leitura == true){
            if (flag_2 == 0){
              digitalWrite(pinLEDS[qual_estado], ! digitalRead(pinLEDS[qual_estado]));
              flag_2 = 1;
              
            }
          }
          else{
            flag_2 = 0;
            }
              break;
        case 3:
          if(leitura == true){
            if (flag_3 == 0){
              digitalWrite(pinLEDS[qual_estado], ! digitalRead(pinLEDS[qual_estado]));
              flag_3 = 1;
              
            }
          }
          else{
            flag_3 = 0;
            }
              break;
      }  
    }
    
}
