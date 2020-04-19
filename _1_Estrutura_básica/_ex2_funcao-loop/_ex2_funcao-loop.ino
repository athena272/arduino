/*-----------AUTOR: GUILHERME R. ALVES---------------
 * Exemplo de sketch com as possibilidades da função "setup()" ++ "loop()";
 * -O programa responde as leituras do ambiente;
 * -Programa vai responder as interações com o circuito aqui;
 * -Faz leitura de estado dos componentes
 * OBS: é executado infinatamente;
 * --------------------------------------------------
 */
//Declarar a variavel "exemploBotao, recebendo o valor inteiro 13"

int exemploBotao = 13; 
int outroexemploBotao = 10;

void setup() {
  // Declarar o pino 13 como saída(OUTPUT)
  pinMode(exemploBotao, OUTPUT);
  //Declar o pino 10 como entrada(INPUT)
  pinMode(outroexemploBotao, INPUT);
  // Inicializar a porta serial
  Serial.begin(9600);
}


// loop checa o estado do botão repetidamente, e envia
// pela serial escrever 'H' se o botão estiver está sendo pressionado
void loop() {
 if (digitalRead(outroexemploBotao) == HIGH ){
     Serial.write('H');
 }
 else{
     Serial.write('L');
 }
 delay(1000);
}
   
