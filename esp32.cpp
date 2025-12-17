#include <WiFi.h>
#include <HTTPClient.h>

const char* WIFI_SSID = "freenetwork.prayash";
const char* WIFI_PASS = "youshallnotpass";

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void sendLog(int fingerId, String pass, int duration) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://localhost:3000/api/log");
    http.addHeader("Content-Type", "application/json");

    String json = "{\"fingerprintId\":" + String(fingerId) +
                  ",\"password\":\"" + pass +
                  "\",\"screenDuration\":" + String(duration) +
                  ",\"event\":\"success\"}";

    http.POST(json);
    http.end();
  }
}

void loop() {
//   sendLog(12, "1234", 3500); yo use garna sak xau fake log
//   delay(10000);
}
