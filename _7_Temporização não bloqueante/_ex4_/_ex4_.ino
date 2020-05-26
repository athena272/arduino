byte btn = 5;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(btn, INPUT);
}

void loop() {
     if(clickSimplesDuplo() == 0){
        Serial.println("0 - nenhum evento detectado no botão.");
     }
     else if(clickSimplesDuplo() == 1){
        Serial.println("1 - pulso simples detectado");
     }
     else if(clickSimplesDuplo() == 2){
        Serial.println("2 - pulso duplo detectado");
     }
}
byte clickSimplesDuplo(){
static byte clicar = 0;
bool b = digitalRead(btn);
static byte apertei = 0;
switch (clicar) {
  case 0:
    if (b == true) {
        if(b == true && apertei == 1){
        clicar = 2;
        apertei = 0;
        }
        else{
        clicar = 1;
        apertei = 1;
        }
    }
  break;

  case 1:
    if (b == false) {
      clicar = 0;
    }

  break;
  case 2:
        if(b == false){
          clicar = 0;
        }
}
return clicar;
}
