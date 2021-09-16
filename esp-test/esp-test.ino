#include <ESP8266WiFi.h>

WiFiServer server(80); //Initialize the server on Port 80

void setup() {

WiFi.mode(WIFI_AP); //Our ESP8266-12E is an AccessPoint
WiFi.softAP("Zohan-Arduino", "thisBeMe"); // Provide the (SSID, password); .
server.begin(); // Start the HTTP Server
Serial.begin(115200); //Start communication between the ESP8266-12E and the monitor window
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
if (client) {
String request = client.readStringUntil('\r');
Serial.println(request);
client.print("Hey man!");
}
//Looking under the hood
IPAddress HTTPS_ServerIP= WiFi.softAPIP(); // Obtain the IP of the Server
Serial.println(HTTPS_ServerIP);
delay(1000);
}
