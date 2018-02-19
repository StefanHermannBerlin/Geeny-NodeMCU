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
- download the [Arduino software](https://www.arduino.cc/en/Main/Software)
– if your NodeMCU is using the CP210x Chip from Silabs, download and install the [USB2UART driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) (you can check, by reading the print on the Chip right behind the USB connector on your NodeMCU)
- in the Arduino IDE go to files and click on the preference
- copy this code *http://arduino.esp8266.com/stable/package_esp8266com_index.json* in the *Additional boards Manager* field
- go to *Tools>Boards Manager...* and enter *esp8266* in the search field
- install the esp8266 by esp8266 community library
- connect your NodeMCU and select it in the *Tools>Port* menue

### Code
- in the Arduino IDE open the example NodeMCU-Blink from this repository
- upload it to the NodeMCU by clicking *Sketch>Upload*

### Manipulate
- Does it work? Great. You see two methods: setup and loop. The setup is executed only once, the loop is repeated for ever.
- Find out, how to make it blink faster!
- 











## Part 2 – DHT22


## Part 3 – Connect to Geeny


