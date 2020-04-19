/*-----------AUTOR: GUILHERME R. ALVES---------------
 * Exemplo de sketch com as possibilidades da função "setup()";
 * -Inicializar variávies;
 * -Configurar os Pinos (INPUT/OUTPUT);
 * -Chamar bibliotecas e portas serias
 * OBS: é executado APENAS uma vez;
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

void loop() {
  // put your main code here, to run repeatedly:
}
