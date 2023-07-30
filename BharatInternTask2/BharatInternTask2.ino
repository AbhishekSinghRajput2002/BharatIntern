#include <ESP8266WiFi.h>
#include <TelegramBot.h>

// Replace with your Wi-Fi credentials
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

// Replace with your Telegram Bot token
const char* telegramToken = "YourTelegramBotToken";

// Initialize the TelegramBot object
TelegramBot bot(telegramToken);

// Define sensor pins
const int bpSensorPin = A0; // Replace with actual pins for your sensors
const int glucometerSensorPin = A1;
const int pulseSensorPin = A2;

void setup() {
  // Start Serial communication for debugging
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read sensor values
  int bloodPressure = analogRead(bpSensorPin);
  int sugarLevel = analogRead(glucometerSensorPin);
  int heartbeat = analogRead(pulseSensorPin);

  // Send sensor data to Telegram
  String message = "Blood Pressure: " + String(bloodPressure) + "\n";
  message += "Sugar Level: " + String(sugarLevel) + "\n";
  message += "Heartbeat: " + String(heartbeat) + "\n";

  // Replace with the chat ID of the healthcare professional's Telegram account
  long chatId = your_chat_id_here;

  // Send the message to the healthcare professional
  bot.sendMessage(chatId, message);

  // Wait for some time before taking the next reading
  delay(30000); // Adjust the delay period based on how often you want to send data
}
