# NodeMCU on Geeny

In this tutorial you will learn, how to connect the NodeMCU to the Geeny platform. 

Material:
- NodeMCU
- LED
- Resistors (220 and 10k)
- DHT22 sensor
- Breadboard and jumper wires

## Part 1 – Blink

We will make an LED blink.

### Setup
- Install Arduino software from www.arduino.cc
- Open the Arduino software and go to files and click on the preference in the Arduino IDE
- Copy the below code in the Additional boards Manager: http://arduino.esp8266.com/stable/package_esp8266com_index.json
- In the Arduino Software go to Tools>Boards>Board Manager
- Navigate to esp8266 by esp8266 community and install the software for Arduino
- Select now from Tools>Board the NodeMCU 1.0 (ESP12E module)
- Install USB driver from software collection folder USB2UART-driver (or https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

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


