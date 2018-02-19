#include <ESP8266WiFi.h>                                          // general library for ESP8266 module
#include <PubSubClient.h>                                         // publish subscribe library
#include <WiFiClientSecure.h>                                     // wifi library with TLS
#include <FS.h>                                                   // library to handle certificates
#include <DHT.h>                                                  // library for DHT22 humidity and temparature sensor

// Replace these with your WiFi network settings
const char* ssid = "Telefonica NEXT Guest";                       // replace this with your WiFi network name
const char* password = "geenyguest";                              // replace this with your WiFi network password
const char* myThingID = "5a680c00-fd75-4dc0-9f5f-b01cab8aab43";   // replace with your device ID

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
