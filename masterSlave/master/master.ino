#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int temperatureSensor = A2;
int gasSensor = A1;
int gasSensorValue;
float reading;
float temperature;
int motor = 8;
char motorOn = 'n';

void setup() {
  Serial.begin(9600);
  pinMode(gasSensor, INPUT);
  pinMode(temperatureSensor, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    motorOn = Serial.read();
    if (motorOn == 'y') {
      digitalWrite(motor, HIGH);
    } else {
      digitalWrite(motor, LOW);
    }
  }

  gasSensorValue = analogRead(gasSensor);
  reading = analogRead(temperatureSensor) * 5.0 / 1023.0;
  temperature = (reading - 0.5) * 100;

  Serial.print(temperature); // Send temperature value over serial
  Serial.print(",");
  Serial.println(gasSensorValue); // Send gas value over serial
  delay(200); // Wait for a second before sending another set of values
}
