/* GEENY Sensors */

#include <ESP8266WiFi.h>                                         // general library for ESP8266 module
#include <DHT.h>                                                 // library for DHT22 humidity and temparature sensor

#define DHTPIN D2                                                // the pin, the DHT22 is connected to
#define DHTTYPE DHT22                                            // the type of the humidity and temparature sensor (DHT22)
DHT dht(DHTPIN, DHTTYPE);                                        // initialising humidity and temparature sensor 

unsigned long lastMillis = 0;                                    // variable used for timer

void setup() {
  Serial.begin(115200);                                          // establishing serial connection for debugging
  Serial.println("Startup");                                     // serial output
}

void loop() {
  if (millis() - lastMillis > 1000) {                            // timer for reading sensor data
    lastMillis = millis();                                       // reset timer
    sendSensorData();                                            // method call
  }

}

void sendSensorData() {                                          
  float theTemparature = dht.readTemperature();                  // read and store temparature
  float theHumidity = dht.readHumidity();                        // read and store humidity

  if (isnan(theHumidity) || isnan(theTemparature)) {             // if data is invalid
    Serial.println("Failed to read from DHT sensor!");           // serial output
    return;                                                      
  }

  Serial.print(theTemparature);                                  // serial output
  Serial.print(" °C\t");
  Serial.print(theHumidity);
  Serial.println(" %");
}
