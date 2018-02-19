// Create a client instance
client = new Paho.MQTT.Client(brokerIp, 8081, "clientId");
client.startTrace();
// set callback handlers
client.onConnectionLost = onConnectionLost;
client.onMessageArrived = onMessageArrived;

// connect the client
client.connect({onSuccess:onConnect});
console.log("attempting to connect...")

// called when the client connects
function onConnect() {
  // Once a connection has been made, make a subscription and send a message.
  client.subscribe(myDeviceID+"/data");
    
  //client.publish("/World", "Hello!", 1, false)

}

// called when the client loses its connection
function onConnectionLost(responseObject) {
  if (responseObject.errorCode !== 0) {
    console.log("onConnectionLost:"+responseObject.errorMessage);
  }
}

// called when a message arrives
function onMessageArrived(message) {
  console.log("onMessageArrived:"+message.payloadString);
  var theData = JSON.parse(message.payloadString);
  document.getElementById("theHumidity").innerHTML  = theData.humidity ;
  document.getElementById("theTemparature").innerHTML  = theData.temparature;
}