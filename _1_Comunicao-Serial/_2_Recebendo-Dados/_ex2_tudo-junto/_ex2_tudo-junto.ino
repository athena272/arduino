/*
*1ª)Leia sobre os Operadores de Comparação, e acrescente a esse programa as seguintes funcionalidades: 
*
*A)se o caractere recebido estiver entre ‘0’ e ‘9’, o Arduino deverá imprimir a mensagem: “Categoria: Dígito numérico”; 
B) se o caractere recebido estiver entre ‘A’ e ‘Z’, o Arduino deverá imprimir a mensagem: “Categoria: Letra maiúscula”; 
C) se o caractere recebido estiver entre ‘a’ e ‘z’, o Arduino deverá imprimir a mensagem: “Categoria: Letra minúscula”; 
D) para qualquer outro caractere, imprimir a mensagem “Categoria: outros”
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
    if(n >= 48 and n <= 57){
      Serial.println("Categoria: Dígito numérico");
    }
    else if (n >= 65 and n <= 90){
      Serial.println("Categoria: Letra Maiúscula");
    }
    else if(n >= 97 and n <= 122){
      Serial.println("Categoria: Letra minúscula");
    }
    else{
      Serial.println("Categoria: outros");
    }
    Serial.print ( n );           //   imprime o valor como um número
    Serial.print ( " | " );       //   imprime a string " | "
    Serial.println ( c );         //   imprime o valor como um caractere
  }
}
