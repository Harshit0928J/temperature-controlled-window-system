# Temperature-Controlled Window System

An ESP32-based automatic window prototype that reads room temperature with a DHT11 sensor and moves a servo-operated window mechanism according to a temperature threshold.

## How it works

- Temperature below **25 °C**: window closes (servo command: 0°).
- Temperature at or above **25 °C**: window opens (servo command: 90°).
- The sensor is read every 2 seconds and the current reading/status is printed to the Serial Monitor.

## Hardware

| Component | Quantity | Purpose |
|---|---:|---|
| ESP32 DevKit V1 | 1 | Main controller |
| DHT11 temperature sensor/module | 1 | Temperature measurement |
| SG90 standard positional servo | 1 | Window movement |
| Regulated 5 V, 1–2 A DC supply | 1 | External servo power |
| Breadboard and jumper wires | As needed | Connections |
| USB data cable | 1 | ESP32 programming and power |
| Window model / linkage | 1 | Mechanical demonstration |

**Servo note:** The code expects a standard positional servo (such as a genuine SG90), which moves to an angle and holds it. A 360° continuous-rotation servo does not interpret 0° and 90° as fixed positions; it behaves more like a speed-controlled motor and needs different control logic/mechanical end-stop handling.

## Wiring

### DHT11

| DHT11 pin | ESP32 |
|---|---|
| VCC | 3V3 |
| DATA / OUT | D15 (GPIO15) |
| GND | GND |

### Servo and power

| Servo wire | Connect to |
|---|---|
| Signal (orange/yellow) | D4 (GPIO4) |
| Red | External regulated +5 V |
| Brown/black | External supply GND |

Connect **ESP32 GND to external supply GND** so the ESP32 and servo share a common ground. Power the ESP32 through USB. Do not connect the servo's external +5 V to the ESP32 3V3 pin. Check supply polarity before powering on.

## Arduino IDE setup

1. Install Arduino IDE.
2. Install ESP32 board support by Espressif Systems and select **ESP32 Dev Module**.
3. Install these libraries through Library Manager:
   - **DHT sensor library** by Adafruit
   - **Adafruit Unified Sensor**
   - **ESP32Servo** by Kevin Harrington
4. Open [src/temperature_controlled_window.ino](src/temperature_controlled_window.ino).
5. Select the ESP32 COM port, upload, then open Serial Monitor at **115200 baud**.

## Configuration

The current pin and threshold settings are at the top of the sketch:

- DHT11 data pin: GPIO15
- Servo signal pin: GPIO4
- Temperature threshold: 25.0 °C
- Closed position: 0°
- Open position: 90°

Adjust the servo angles to suit the physical window linkage. With the horn detached, test the servo positions first; switch off power before changing the horn position. Do not force the servo shaft by hand.

## Troubleshooting

- **“Sensor reading failed!”**: check DHT11 VCC, GND and DATA wiring, and confirm the sketch uses GPIO15.
- **Servo does not move**: verify the external regulated 5 V supply, correct polarity, D4 signal wire, and common ground.
- **Window stays closed**: the measured temperature must be at least 25 °C for the open command.
- **Upload succeeds but nothing moves**: upload success only confirms the sketch was transferred; check Serial Monitor output and servo power separately.
- A standard servo normally moves to a requested position rather than spinning continuously.

## Repository structure

```
temperature-controlled-window-system/
├── README.md
├── src/
│   └── temperature_controlled_window.ino
└── docs/
    └── wiring-and-operation.md
```

## Safety

Use only a properly regulated, low-voltage 5 V DC supply for the servo. Do not work with exposed mains wiring. Check all connections before applying power.

## Project status

This repository contains the current wiring plan and Arduino sketch. Add your own verified photographs, measured test results, and final mechanical design as the physical prototype is completed.
