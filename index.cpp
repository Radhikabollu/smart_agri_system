
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define SOIL_MOISTURE_PIN A0
#define RELAY_PIN D1
#define TRIGGER_PIN D2
#define ECHO_PIN D3
#define BUZZER_PIN D4

#define WIFI_SSID "12345678"
#define WIFI_PASSWORD "12345678"
#define API_KEY "AIzaSyCvE5kjznXHxvdRnnVw8GWlee9SucxPXW4"
#define DATABASE_URL "https://smart-agriculture-system-d93f4-default-rtdb.firebaseio.com/"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  digitalWrite(RELAY_PIN, LOW);





 }
        if (distance < 20.0) {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Object detected within 20 cm. Buzzer is ON.");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("No object detected within 20 cm. Buzzer is OFF.");
  }

  Serial.print("Soil Moisture Level: ");
  Serial.println(soilMoisture);
  Serial.print("Ultrasonic Distance: ");
  Serial.println(distance);
  Serial.println();

  delay(1000);

  if (Firebase.ready()) {
    if (Firebase.RTDB.setInt(&fbdo, "mainbucket/soil_moisture", soilMoisture)) {
      Serial.println("Soil moisture data sent to Firebase");
    } else {
      Serial.println("Failed to send soil moisture data to Firebase");
    }

    // Send ultrasonic distance data to Firebase
    if (Firebase.RTDB.setFloat(&fbdo, "mainbucket/ultrasonic_distance", distance)) {
      Serial.println("Ultrasonic distance data sent to Firebase");
    } else {
               Serial.println("Failed to send ultrasonic distance data to Firebase");
    }
  }
              }

float readUltrasonicDistance() {
 

 digitalWrite(TRIGGER_PIN, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration * 0.0343) / 2;

  return distance;











