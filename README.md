# NodeMCU on Geeny




In this tutorial you will learn, how to connect the NodeMCU to the Geeny platform.




## Material
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

## Part 1.1 – Blink

1. Open *Files>Examples>Basics>Blink*
2. Go to *Tools>Port* and select (usually) the last entry
3. Upload the code to the NodeMCU: *Sketch>Upload* or click the upload button in the menu

![alt text](https://github.com/StefanHermannBerlin/Geeny-NodeMCU/blob/master/assets/upload.png)

4. The LED should blink now

## Part 1.2

1. Now change the circuit

![Circuit: Fritzing diagram](https://github.com/StefanHermannBerlin/Geeny-NodeMCU/blob/master/assets/blink-fritzing.png)
(Diagram made with Fritzing)

2. Change the sketch or open the file *1_blink.ino* in the Arduino IDE
3. Upload the code to the NodeMCU

## Part 2 – DHT22 Temperature and Humidity sensor 

1. Change the circuit to this one

![Circuit: Fritzing diagram](https://github.com/StefanHermannBerlin/Geeny-NodeMCU/blob/master/assets/dht22-fritzing.png)

(Diagram made with Fritzing)
2. Open the Arduino sketch *2_DHT22.ino*
3. After uploading the sketch, open the Serial Monitor
![Circuit: How to open the Serial Monitor.](https://github.com/StefanHermannBerlin/Geeny-NodeMCU/blob/master/assets/serial-monitor.png)


## Part 3 – Connect to Wifi

1. Open the Sketch *3_DHT22Wifi.ino*
2. Change the Wifi credentials (to your network)
3. Open the Serial Monitor
4. Click the Reset Button on the NodeMCU -> It will say connected, if it connects properly 
![Circuit: How to open the Serial Monitor.](https://github.com/StefanHermannBerlin/Geeny-NodeMCU/blob/master/assets/reset-button.png)

## Intermetzzo

### I.1 Create a Geeny account
1. Go to Geeny.io and create a new account
2. Click on Become a developer (in the popup click skip)

### I.2 Create a *new Thing*
1. Click on Devices
2. Click on Register a new Thing
3. fill out the form:
4. give it a name you like, 
5. a serial number (a new UUID e.g. from [UUID Generator](www.uuidgenerator.net))
6. and select the Thing Type NodeMCU+DHT22_1
7. Click on Register this Thing
8. Now a screen opens asking to download the certificate files. Save the files on your computer by clicking each file.
9. On the Device overview page you see your newly created Thing. Click on See logs
10. Copy the Thing-ID shown on top of the page and save it somewhere (BTW: this is where we will see the data later on)

### I.3 Upload Certificates

#### Generate DER files
For the NodeMCU we need the Certificates in a binary format. This is how to create it:

#### OSX
1. Open a Terminal window and navigate to the folder where you stores the certificate files
2. Enter the two following commands
    $ openssl rsa -outform der -in thing.key -out thing-key.der
    $ openssl x509 -outform der -in thing.crt -out thing-crt.der
4. Now you should see two new files in your folder with the file extension .der
5. Copy this files into the data folder of your Sketch (4_DHT22Geeny)

#### Windows

1. Download and install OpenSSL from [slproweb](slproweb.com/products/Win32OpenSSL.html) (File: Win32 OpenSSL v1.1.0g Light)
2. Copy the Certificates to C:\Geeny
3. Open a Command Window (Windows+R and enter CMD)
4. Go to C:\OpenSSL-Win32\bin and run openssl.exe
5. Enter the two following commands
    $ openssl rsa -outform der -in c:\Geeny\thing.key  -out c:\Geeny\thing-key.der
    $ openssl x509 -outform der -in c:\Geeny\thing.crt  -out c:\Geeny\thing-crt.der
6. Now you should see two new files with the file extension .der in this folder
7. Copy this files into the data folder of your Sketch (4_DHT22Geeny)



1. In order to upload the certificates to the NodeMCE, you need this [plugin](https://github.com/esp8266/arduino-esp8266fs-plugin/releases/download/0.2.0/ESP8266FS-0.2.0.zip) for the Arduino IDE
2. In your Arduino sketchbook directory, create tools directory if it doesn't exist yet
3. Unpack the tool into tools directory (*../Arduino/tools/ESP8266FS/tool/esp8266fs.jar*)
4. Restart Arduino IDE
5. In the *Tools* menu set the CPU frequency to 160 MHz
6. Click on *Tools>ESP8266 Sketch Data Upload*



## Part 4 - Connect to Geeny

1. In the Arduino IDE go to *Sketch>Include Library>Manage libraries ...* and search for *PubSubClient*
2. Install the *PubSubClient by Nick O'Leary* library
3. Open the Sketch 4_DHT22Geeny.ino
4. Change the Wifi credentials (to your network)
5. Change *myThingID* to the one you copied from the *Device logs* page

![Copy the thingID](https://github.com/StefanHermannBerlin/Geeny-NodeMCU/blob/master/assets/thingID.png)

6. Upload the sketch to your NodeMCU
7. Check the serial monitor

## Outlook

That's all folks, but check out our [Documentation Center](docs.geeny.io) to learn to build an application using the data we now connected. 

### Let's stay in touch:

Geeny.io
@geeny.io

Stefan Hermann
stefan.h@geeny.io
@stefanhermann