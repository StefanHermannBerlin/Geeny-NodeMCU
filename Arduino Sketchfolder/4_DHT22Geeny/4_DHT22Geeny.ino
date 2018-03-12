#include <ESP8266WiFi.h>                                          // general library for ESP8266 module
#include <PubSubClient.h>                                         // publish subscribe library
#include <WiFiClientSecure.h>                                     // wifi library with TLS
#include <FS.h>                                                   // library to handle certificates
#include <DHT.h>                                                  // library for DHT22 humidity and temparature sensor

// Replace these with your WiFi network settings
const char* ssid = "Telefonica NEXT Guest";                         // replace this with your WiFi network name
const char* password = "geenyguest";                              // replace this with your WiFi network password
const char* myThingID = "a9593273-3d83-44b0-87b8-739fdeb737b6";   // replace with your Thing ID (table below)

/*
NodeMCU 01: a9593273-3d83-44b0-87b8-739fdeb737b6
NodeMCU 02: 30edb97d-c5ef-4683-a893-ed07f2cb9fb3
NodeMCU 03: 89ab1afd-92d1-4106-9bbf-b890aced1656
NodeMCU 04: 5530d773-0fc1-4ec1-a734-b10595f5c3c5
NodeMCU 05: d1cd8983-35be-480d-9491-da17a7c66608
NodeMCU 06: 0c1fe26d-b222-490b-bc9b-2603b04b97ed
NodeMCU 07: b2ea77d4-28fa-4253-85b2-b560e02591c8
NodeMCU 08: 8fad8ad0-818b-4576-9ad6-dd07bd3bbd20
NodeMCU 09: e734c186-6c07-427a-a236-916861cd3fc9
NodeMCU 10: e3c64659-03d5-4525-8e1a-d358976d6b8c
*/

#define DHTPIN D2                                                 // the pin, the DHT22 is connected to
#define DHTTYPE DHT22                                             // the type of the humidity and temparature sensor (DHT22)
DHT dht(DHTPIN, DHTTYPE);                                         // initialising humidity and temparature sensor

unsigned long lastMillis = 0;                                     // variable used for timer

const char* mqttServer = "mqtt.geeny.io";                         // the mqtt url from Geeny
const int mqttPort = 8883;                                        // the mqtt port

WiFiClientSecure espClient;                                       // tls wifi client
PubSubClient client(espClient);                                   // pubsub client

bool isConnected = false;                                         // flag

void setup() {
  Serial.begin(9600);                                             // establish serial communication for debugging
  connectToWifi();                                                // connect to Wifi
  connectToGeeny();                                               // connect to Geeny
}

void loop() {
  if (isConnected) {
    if (millis() - lastMillis > 1000) {                            // timer for reading sensor data
      lastMillis = millis();                                       // reset timer
      sendSensorData();                                            // method call
    }
  }
}

void sendSensorData() {
  float theTemparature = dht.readTemperature();                    // read and store temparature
  float theHumidity = dht.readHumidity();                          // read and store humidity

  if (isnan(theHumidity) || isnan(theTemparature)) {               // if data is invalid
    Serial.println("Failed to read from DHT sensor!");             // serial output
    return;
  }

  Serial.print(theTemparature);                                    // serial output
  Serial.print(" °C\t");                                           // serial output
  Serial.print(theHumidity);                                       // serial output
  Serial.println(" %");                                            // serial output

  client.publish("humidity", &String(theTemparature)[0u]);         // publishing data to Geeny
  client.publish("temperature", &String(theHumidity)[0u]);         // publishing data to Geeny
  Serial.println("Published ...");                                 // serial output
}
