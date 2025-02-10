#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define ldrPin 34
#define redLed 14
#define blueLed 32
#define greenLed 27

// Configure your WiFi credentials
const char* ssid = "myWifiNetwork";
const char* password = "*******";

const char* MQTTBroker = "xxxxxxxxxxxxxxxxxxx.s1.eu.hivemq.cloud";
const int MQTTPort = 8883; // don't change it
const char* MQTTUsername = "**********";
const char* MQTTPassword = "**********";

const char* topicLDR = "esp32/ldr";
const char* topicLed = "esp32/leds";

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

unsigned long previousTime = 0;

int value;
String stringValue;

void reconnect() {
  Serial.println("Connecting to MQTT Broker...");

  while (!mqttClient.connected()) {
    Serial.println("Reconnecting to MQTT Broker...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX); // random hexadecimal string

    if (mqttClient.connect(clientId.c_str(), MQTTUsername, MQTTPassword)) {
      Serial.println("Connected to MQTT Broker.");

      mqttClient.subscribe(topicLDR);
      mqttClient.subscribe(topicLed);
    } else {
      Serial.print("Failed, code =");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived (");
  Serial.print(topic);
  Serial.print("): ");

  String message;
  for (int i = 0; i < length; i++)
    message += (char)payload[i];

  Serial.println(message);

  // Control received messages
  if (message == "redled-on") {
    Serial.println("Turning on Red LED");
    digitalWrite(redLed, HIGH);
  } else if (message == "redled-off") {
    Serial.println("Turning off LED");
    digitalWrite(redLed, LOW);
  }
  
  if (message == "blueled-on") {
    Serial.println("Turning on Blue LED");
    digitalWrite(blueLed, HIGH);
  } else if (message == "blueled-off") {
    Serial.println("Turning off Blue LED");
    digitalWrite(blueLed, LOW);
  }

  if (message == "greenled-on") {
    Serial.println("Turning on Green LED");
    digitalWrite(greenLed, HIGH);
  } else if (message == "greenled-off") {
    Serial.println("Turning off Green LED");
    digitalWrite(greenLed, LOW);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to Wi-Fi");

  // Initialize secure WiFiClient
  wifiClient.setInsecure();
  
  mqttClient.setServer(MQTTBroker, MQTTPort);
  mqttClient.setCallback(mqttCallback);
}

void loop() {
  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();

  unsigned long currentTime = millis();
  if (currentTime - previousTime > 1000) { // Publish it every 1 seconds (don't use delay because MQTT connection may be interrupted)
    previousTime = currentTime;

    value = analogRead(ldrPin);
    
    // You need to convert the value to a string to publish it
    stringValue = String(value);
    
    // Publish the sensor value to the MQTT topic
    mqttClient.publish(topicLDR, stringValue.c_str());
  }
}