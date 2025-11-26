#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ZTE_CAC0B1";
const char* password = "8SBDQU3KE5";

WebServer server(80);

void handleTurnOnLed7() {
  strip.setPixelColor(NUM_LEDS - 1, strip.Color(0, 255, 0));
  strip.show();
  server.send(200, "text/plain", "LED 7 turned ON");
}

void handleTurnOffLed7() {
  strip.setPixelColor(NUM_LEDS - 1, strip.Color(0, 0, 0)); // כבוי
  strip.show();
  server.send(200, "text/plain", "LED 7 turned OFF");
}

void startHttpServer() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/led7/on", handleTurnOnLed7);
  server.on("/led7/off", handleTurnOffLed7);
  server.begin();
  Serial.println("HTTP server started");
}

void handleClient() {
  server.handleClient();
}
