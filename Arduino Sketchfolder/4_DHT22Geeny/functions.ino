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

void connectToGeeny(){
  // exchanging certificats and creating a secure communication way to Geeny
  SPIFFS.begin();
  File ca = SPIFFS.open("/thing-crt.der", "r");

  if (!ca) {
    Serial.println("Couldn't load cert");
    return;
  }

  if (espClient.loadCertificate(ca)) {
    Serial.println("Loaded Cert");
  } else {
    Serial.println("Didn't load cert");
    return;
  }

  File key = SPIFFS.open("/thing-key.der", "r");
  if (!key) {
    Serial.println("Couldn't load key");
    return;
  }

  if (espClient.loadPrivateKey(key)) {
    Serial.println("Loaded Key");
  } else {
    Serial.println("Didn't load Key");
  }

  client.setServer(mqttServer, mqttPort);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect(myThingID)) {
      Serial.println("connected");
      isConnected = true;
    } else {
      Serial.print("failed with state ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}
