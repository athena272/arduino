//------Vetores e Laços--------------
/*
Na questão anterior, o acionamento do LED indicador 
foi controlado pelo valor analógico de um potenciômetro. 
Faça a mesma funcionalidade, agora controlando com 
dois botões digitais: a cada pulso no botão[1], 
o LED ativo desloca-se para a direita (+1), 
e a cada pulso no botão[0], o LED ativo desloca-se 
para a esquerda (-1).
*/


//Variáveis Globais
const byte led[8] = {13, 12, 11, 10, 9, 8, 7, 6};  //Pinos LEDS
const byte btn[2] = {5, 4}; //Pinos Buttons

void setup() {
  for(byte dl = 0; dl <= 7; dl++){ //Declaração de LEDS
    pinMode(led[dl], OUTPUT);
  }
  for(byte db = 0; db <= 1; db++){ //Declaração de Buttons
    pinMode(btn[db], INPUT);
  }
  Serial.begin(9600); //Iniciar Simulador
}
void loop(){
    for(int i = -1; i <= 6; i++){
      if(digitalRead(btn[1]) == true){
        digitalWrite(led[i], LOW);
        digitalWrite(led[i + 1], HIGH);
        //Monitorar a posição do led
        Serial.print("Posição de Led[0-7]: ");
        Serial.println(i + 1);
      }  
    }
    for(int i = 1; i <= 8; i++){
      if(digitalRead(btn[0]) == true){
        digitalWrite(led[i], LOW);
        digitalWrite(led[i - 1], HIGH);
        Serial.print("Posição de Led[0-7]: ");
        Serial.println(i - 1);
      }  
    }
}
