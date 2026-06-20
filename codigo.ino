#include <WiFi.h>
#include <PubSubClient.h>

// ===== WIFI =====
const char* ssid = "SEU_WIFI";
const char* password = "SUA_SENHA";

// ===== MQTT =====
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// ===== PINOS =====
const int sensorPin = 4;
const int ledPin = 2;
const int buzzerPin = 15;

void setup_wifi() {
  delay(10);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32_Postura")) {
      break;
    }
    delay(5000);
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  setup_wifi();

  client.setServer(mqtt_server, 1883);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  int estadoSensor = digitalRead(sensorPin);

  if (estadoSensor == HIGH) {

    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);

    client.publish(
      "cadeira/postura",
      "POSTURA_INCORRETA"
    );

  } else {

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    client.publish(
      "cadeira/postura",
      "POSTURA_CORRETA"
    );
  }

  delay(1000);
}
