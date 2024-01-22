#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char *ssid = "Elconics";
const char *password = "Elconics@789";

// Create an instance of the ESP8266WebServer class
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Define the HTTP handler
  server.on("/", HTTP_GET, handleRoot);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Handle client requests
  server.handleClient();
}

// HTTP handler for the root URL
void handleRoot() {
  String message = "Hello, this is Elconics WebServer";
  
  server.send(200, "text/plain", message);
}
