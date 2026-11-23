#include <DHT.h>
#include <ESP32Servo.h>

// DHT11 configuration
#define DHTPIN 15
#define DHTTYPE DHT11

// Servo configuration
#define SERVOPIN 4

// Temperature threshold
#define TEMP_LIMIT 25

// Servo angles (exchanged)
#define OPEN_ANGLE 0
#define CLOSE_ANGLE 90

DHT dht(DHTPIN, DHTTYPE);
Servo windowServo;

void setup() {

  Serial.begin(115200);

  dht.begin();

  windowServo.setPeriodHertz(50);
  windowServo.attach(SERVOPIN, 500, 2400);

  // Initially close the window
  windowServo.write(CLOSE_ANGLE);

  Serial.println("Temperature Controlled Window System");
  Serial.println("-------------------------------------");

  delay(2000);
}

void loop() {

  float temperature = dht.readTemperature();

  // Check sensor reading
  if (isnan(temperature)) {

    Serial.println("Sensor reading failed!");

    delay(2000);
    return;
  }

  // Display temperature
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Window control
  if (temperature < TEMP_LIMIT) {

    windowServo.write(CLOSE_ANGLE);

    Serial.println("Window CLOSED");

  } else {

    windowServo.write(OPEN_ANGLE);

    Serial.println("Window OPEN");

  }

  Serial.println("-------------------------------------");

  delay(2000);
}