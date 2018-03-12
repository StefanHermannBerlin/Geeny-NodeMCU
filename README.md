# NodeMCU on Geeny




In this tutorial you will learn, how to connect the NodeMCU to the Geeny platform.




Material:
- NodeMCU
- LED
- Resistors (220 and 10k)
- DHT22 sensor
- Breadboard and jumper wires

## Setup
1. Install Arduino IDE from [Arduino.cc](http://www.arduino.cc)
2. Go to *Files>Preference* (Mac: *Arduino>Preferences*) in the Arduino IDE
3. Copy the below link in the Additional boards Manager field: *http://arduino.esp8266.com/stable/package_esp8266com_index.json*
4. Go to *Tools>Boards>Board Manager*
5. Search for *esp8266* (by esp8266 community) and install it
6. Select from *Tools>Board* the NodeMCU 1.0 (ESP12E module)
7. Install USB driver from [Silabs](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
8. Copy the content of the *Arduino Sketchfolder* in this repository into your Arduino Sketchfolder 

## Part 1 – Blink

1. Open *Files>Examples>Basics>Blink*
2. Go to *Tools>Port* and select (usually) the last entry
3. Upload the code to the NodeMCU: *Sketch>Upload* or click the upload button in the menu
![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/ico



### Code
- in the Arduino IDE open the example NodeMCU-Blink from this repository
- upload it to the NodeMCU by clicking *Sketch>Upload*

### Manipulate
- Does it work? Great. You see two methods: setup and loop. The setup is executed only once, the loop is repeated for ever.
- Find out, how to make it blink faster!
- 











## Part 2 – DHT22


## Part 3 – Connect to Geeny


----
openssl rsa -outform der -in thing.key -out thing-key.der
openssl x509 -outform der -in thing.crt -out thing-crt.der


