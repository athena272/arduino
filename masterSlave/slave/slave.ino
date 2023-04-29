#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C display1(32, 16, 2);
LiquidCrystal_I2C display2(33, 16, 2);
int currentMillis = 0;
int runningTime = 0;
int buzzer = 13;
int stop = 0;

int gasSensorValue;
int gasLevel = 0;
float temperature;
int button = 2;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button), handleInterrupt, RISING);

  display1.init();
  display2.init();
  display1.backlight();
  display2.backlight();
  display1.setCursor(0, 0);

  display1.print("Temp:");
  display1.setCursor(6, 1);
  display1.print("C");
  display1.setCursor(0, 1);
  display2.setCursor(0, 0);
  display2.print("Gas Level:");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');

    int index = data.indexOf(',');

    temperature = data.substring(0, index).toFloat();
    gasSensorValue = data.substring(index + 1).toInt();

    if (gasSensorValue > 600) {
      gasLevel = 3;
    } else if (gasSensorValue > 500) {
      gasLevel = 2;
    } else if (gasSensorValue > 400) {
      gasLevel = 1;
    } else {
      gasLevel = 0;
    }

    display1.setCursor(0, 1);
    display1.print(temperature);
    display2.setCursor(0, 1);
    display2.print(gasLevel);

    if (gasLevel > 0 && temperature > 50) {

      if (millis() > runningTime + 500 && stop == 0) {
        runningTime = millis();
        tone(buzzer, 1500);
        Serial.println('y');
      }
    } else {
      noTone(buzzer);
      runningTime = millis();
      Serial.println('n');
    }
  }
}

void handleInterrupt() {
  noTone(buzzer);
  Serial.println('n');
  if (stop == 1) {
    stop = 0;
  } else {
    stop = 1;
  }
}
