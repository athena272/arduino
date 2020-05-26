
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
        Serial.println("1 - o botão foi pressionado nesse momento");
     }
     else if(clickSimplesDuplo() == 2){
        Serial.println("2 - pulso duplo detectado");
     }
}
byte clickSimplesDuplo(){
unsigned long ta = millis();
static unsigned long t0 = 0; 
static byte clicar = 0;
bool b = digitalRead(btn);
static byte apertei = 0;
switch (clicar) {
  case 0:
    if (b == true) {
        if(b == true && apertei == 1 ){
            apertei = 0;
            clicar = 2;
          
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
        break;
}
return clicar;
}
