void connectToWifi(){
  WiFi.begin(ssid, password);                                     // connect to wifi

  Serial.print("Connecting");                                     // serial output
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");                                            // serial output
  }

  Serial.print("Wifi connected, IP Address is: ");                // serial output
  Serial.println(WiFi.localIP());                                 // serial output  
}
