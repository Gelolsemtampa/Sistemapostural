// Pinos
const int sensorPin = 2;   // Botão simulando sensor
const int ledPin = 13;     // LED
const int buzzerPin = 8;   // Buzzer

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int estadoSensor = digitalRead(sensorPin);

  if (estadoSensor == HIGH) {
    // Postura incorreta
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000); // som
  } else {
    // Postura correta
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}
