// You must fill in these 3 lines with the info from your Blynk Web Dashboard
#define BLYNK_TEMPLATE_ID "TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "AUTH_TOKEN"

// Print messages to the Serial Monitor
#define BLYNK_PRINT Serial

// ESP8266 Specific Libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your network details
char ssid[] = "Wifi-Name";
char pass[] = "Wifi-Password";

// Assign output variables to NodeMCU pins (D1 and D2)
const int relay1 = D1; 
const int relay2 = D2; 

void setup() {
  Serial.begin(115200);

  // Initialize the relay pins as outputs
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  // Set relays to HIGH (Most 5V relays are active LOW, so HIGH keeps them OFF initially)
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// This function runs when the Virtual Pin V0 state changes in the Blynk App
BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); 
  if (pinValue == 1) {
    digitalWrite(relay1, LOW); // Turn Relay 1 ON
    Serial.println("Relay 1 ON");
  } else {
    digitalWrite(relay1, HIGH); // Turn Relay 1 OFF
    Serial.println("Relay 1 OFF");
  }
}

// This function runs when the Virtual Pin V1 state changes in the Blynk App
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); 
  if (pinValue == 1) {
    digitalWrite(relay2, LOW); // Turn Relay 2 ON
    Serial.println("Relay 2 ON");
  } else {
    digitalWrite(relay2, HIGH); // Turn Relay 2 OFF
    Serial.println("Relay 2 OFF");
  }
}

void loop() {
  Blynk.run();
}