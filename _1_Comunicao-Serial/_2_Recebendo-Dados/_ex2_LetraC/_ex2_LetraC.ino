/*
*1ª)Leia sobre os Operadores de Comparação, e acrescente a esse programa as seguintes funcionalidades: 
*C) se o caractere recebido estiver entre ‘a’ e ‘z’, 
*o Arduino deverá imprimir a mensagem: “Categoria: Letra minúscula”;

 */
void setup() {
  Serial.begin(9600);  // inicializa comunicação serial (9600 bits/s)
}

void loop() {
  delay (100);          // (somente para a simulação) 
  byte n = 0;          // declara variável n, e inicializa com valor 0
  char c;              // declara variável c (não inicializa)

  if ( Serial.available() > 0 ) { // se existem caracteres na fila de entrada
    c = Serial.read();            //   leia 1 caractere da fila de entrada
    n = c;                        //   atribua a n o valor de c
    if(n >= 97 and n <= 122){
      Serial.println("Categoria: Letra minúscula");
    }
    Serial.print ( n );           //   imprime o valor como um número
    Serial.print ( " | " );       //   imprime a string " | "
    Serial.println ( c );         //   imprime o valor como um caractere
  }
}
