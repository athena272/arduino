//------------Vetores e laços de repetição---------- 
/*
* Implemente agora um comportamento diferente: 
* o sistema deverá CONTAR quantos botões estão 
* pressionados ao mesmo tempo, e acender somente 
* 1 LED, correspondente a essa contagem. 
* Ex: se 3 botões estiverem pressionados 
* (não importa quais botões), somente o LED 3 deverá 
* estar aceso. Se nenhum botão estiver pressionado, 
* nenhum LED estará aceso.
DICA: use laço for para fazer a contagem de 
quantos botões estão pressionados, 
e depois, outro laço for para ativar / desativar os LEDs, 
de acordo com a contagem.
*/
const byte led[3] = {13, 12, 11};
const byte button[3] = {7, 6, 5};
  
void setup() {
  //Declarar led
  byte dl; //variavel declarar led
  for(dl = 0; dl <= 2; dl++){
     pinMode(led[dl], OUTPUT);
  }
  //Declarar botão
  byte db; //variável declarar botão
  for(db = 0; db <= 2; db++){
      pinMode(button[db], INPUT);  
  }
  //Iniciar monitor Serial
  Serial.begin(9600);
}

void loop() {
  //Laço para botões pressionados
  byte lista_estados[3]; //Variável para guardar 3 estados em um array
  //Loop encontrar estados
  for(byte n_b = 0; n_b <= 2; n_b++){ //numero de botões, variavel de loop
     //Ler estado dos botão
     bool estadoY = digitalRead(button[n_b]); //Ler estado do botão
     lista_estados[n_b] = estadoY; //Adicionar o estado no array(lista)
  }
  //Esse loop faz a soma interna no array
  byte soma = 0;
  for(byte i = 0; i <= 2; i++){
       soma += lista_estados[i]; //Aqui está o valor da soma interna do array
  }
  if(soma > 0){ //se pelo um botõa estiver pressionado
    for(byte y = 0; y <= 2; y++){ //Loop para apagar leds
     digitalWrite(led[y], LOW);
     digitalWrite(led[soma - 1], HIGH); 
     //mas deixa um led acesso que tem a quantia de buttons menos 1, para achar pos LED do certo
    }
  }
  else{ //Se for igual a zero(nenhum botão pressionado)
      for(byte j = 0; j <= 2; j++){ //Loop apaga geral, sem exceção
          digitalWrite(led[j], LOW); 
      }
  }  
  //--------------PRINTS--------------------
  Serial.print(soma); //numero de botões pressionados
  Serial.print("||");
  Serial.println(soma - 1); //Posição do led a ser acesso
}
 
