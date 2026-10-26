#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include "DHTesp.h"


const int DHT_PIN = 15;
DHTesp dhtSensor;


const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* apiKey = "E0G8CV4F7XGOHQ26";

const char* universityID = "12240090";

void setup() {
  Serial.begin(115200);


  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  Serial.println("ESP32 Temperature and Humidity Monitoring");
  Serial.print("University ID: ");
  Serial.println(universityID);


  WiFi.begin(ssid, password, 6);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
}

void loop() {

  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  float temperature = data.temperature;
  float humidity = data.humidity;

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22 sensor!");
    delay(20000);
    return;
  }

  Serial.println("-------------------------");

  Serial.print("University ID: ");
  Serial.println(universityID);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (WiFi.status() == WL_CONNECTED) {

    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient http;

    String url = "https://api.thingspeak.com/update?api_key=";
    url += String(apiKey);
    url += "&field1=" + String(temperature, 2);
    url += "&field2=" + String(humidity, 2);

    http.begin(client, url);

    int httpCode = http.GET();

    if (httpCode == 200) {

      String response = http.getString();

      if (response.toInt() > 0) {
        Serial.println("Data sent successfully!");
        Serial.print("ThingSpeak Entry ID: ");
        Serial.println(response);
      } else {
        Serial.println("ThingSpeak rejected the update.");
      }

    } else {
      Serial.print("HTTP Error: ");
      Serial.println(httpCode);
    }

    http.end();

  } else {
    Serial.println("WiFi disconnected!");
    WiFi.reconnect();
  }

  delay(20000);
}