/*-----------AUTOR: GUILHERME R. ALVES--------------------
 * Criando minhas próprias funcoes
 * ----Vamos lá!!!!!!!!!!
 */

//Função para somar duas variáveis:
int X;
int soma(int a, int b) {
      return a + b;
  }
//Fim criação função
void setup() {
  //Iniciar Monitor Serial para vermos os valores sendo somados neles
  Serial.begin(9600);
  X = soma(13, 17);
  Serial.print(X);
}

void loop() {
  // put your main code here, to run repeatedly:

}
