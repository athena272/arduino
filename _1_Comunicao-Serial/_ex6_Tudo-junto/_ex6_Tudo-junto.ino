/*-----------AUTOR: Fábio Prudente---------------
 * TUDO desse modulo
 * -Incremento
 * -Serial e suas funções begin, print, println
 */

void setup() {
  Serial.begin(9600);     // inicializa comunicação serial (9600 bits/s)
}

void loop() {
  delay (100);             // pausa o programa, por 100ms
  static byte n = 0;      // declara variável n, do tipo byte, e inicializa com 0
  char c = n;             // declara variável c, do tipo char, e atribui valor de n
  Serial.print ( n );     // imprime o valor como um número (pq???)
  Serial.print ( " | " );  // imprime uma string ( " | " )
  Serial.println ( c );    // imprime o mesmo valor como um caractere (pq???)
  n++;                    // incrementa valor de n (faz n = n + 1)
}
