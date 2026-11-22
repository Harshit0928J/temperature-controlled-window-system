#include <DHT.h>
#include <ESP32Servo.h>

// Hardware connections
#define DHT_PIN 15       // D15 = GPIO15
#define DHT_TYPE DHT11
#define SERVO_PIN 4      // D4 = GPIO4

// Window control settings
#define TEMP_THRESHOLD 25.0
#define WINDOW_CLOSED_ANGLE 0
#define WINDOW_OPEN_ANGLE 90

DHT dht(DHT_PIN, DHT_TYPE);
Servo windowServo;

void setup() {
  Serial.begin(115200);
  dht.begin();

  windowServo.setPeriodHertz(50);
  windowServo.attach(SERVO_PIN, 500, 2400);
  windowServo.write(WINDOW_CLOSED_ANGLE);

  Serial.println();
  Serial.println("Temperature Controlled Window System");
  Serial.println("System Started");
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Sensor reading failed! Check DHT11 wiring.");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  if (temperature >= TEMP_THRESHOLD) {
    windowServo.write(WINDOW_OPEN_ANGLE);
    Serial.println("Window: OPEN");
  } else {
    windowServo.write(WINDOW_CLOSED_ANGLE);
    Serial.println("Window: CLOSED");
  }

  Serial.println("------------------------------");
  delay(2000);
}
