/*---------AUTOR: Guilherme R. Alves----------
 * Comandos: 
 * Serial.begin(taxa de transmição);
 * Serial.print(Alguma mensagem);
 * Serial.println(Alguma mensagem pulando linha);
 * ----------------------------------------------
 *Um segundo parâmetro opcional especifíca a base (formato) a ser usada; 
 *valores permitidos são BIN(binário, ou base 2), OCT(octal, ou base 8), DEC(decimal, ou base 10), HEX(hexadecimal, ou base 16). 
 *Para números de ponto flutuante, esse parâmetro especifica o número de casas decimais a serem impressas. Por exemplo:

    Serial.print(78, BIN) imprime "1001110"

    Serial.print(78, OCT) imprime "116"

    Serial.print(78, DEC) imprime "78"

    Serial.print(78, HEX) imprime "4E"

    Serial.print(1.23456, 0) imprime "1"

    Serial.print(1.23456, 2) imprime "1.23"

    Serial.print(1.23456, 4) imprime "1.2346"
 * ----------------------------------------------
 */
 void setup(){
  //Iniciando monitor serial
  Serial.begin(9600);
  //Imprimindo alguns valores
  Serial.print('-');
  Serial.println("PROFESSORA LINDA!");
  Serial.println(78, BIN); //imprime "1001110"

    Serial.println(78, OCT); //imprime "116"

    Serial.println(78, DEC); //imprime "78"

    Serial.println(78, HEX); //imprime "4E"

    Serial.println(1.23456, 0); //imprime "1", pois não queremos casas decimais

    Serial.println(1.23456, 2); //imprime "1.23", pois queremos duas casas decimais

    Serial.println(1.23456, 4); //imprime "1.2346", pois queremos 4  casas decimais
  }
 void loop(){
  
 }
 
