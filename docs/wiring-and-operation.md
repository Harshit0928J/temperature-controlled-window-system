# Wiring and Operation

## Pin connections

### DHT11 to ESP32
- VCC -> 3V3
- DATA/OUT -> D15 (GPIO15)
- GND -> ESP32 GND

### Servo to ESP32 and external supply
- Signal (orange/yellow) -> D4 (GPIO4)
- Red -> regulated external +5 V
- Brown/black -> external supply GND
- ESP32 GND -> external supply GND (common ground)

Keep the ESP32 powered/programmed by USB. Do not connect external +5 V to the ESP32 3V3 pin. Verify supply polarity before switching on.

## Operating sequence

1. Connect the DHT11 and servo as shown above.
2. Install Adafruit DHT, Adafruit Unified Sensor, and ESP32Servo libraries.
3. Select **ESP32 Dev Module** in Arduino IDE and the correct COM port.
4. Upload `src/temperature_controlled_window.ino`.
5. Open Serial Monitor at 115200 baud.
6. Below 25 °C the sketch commands 0° (closed); at or above 25 °C it commands 90° (open).

## Important servo distinction

This sketch is for a standard positional servo. A continuous-rotation 360° servo will not stop at a fixed angle using `write(0)` / `write(90)`; it needs a different control approach. Confirm the servo type before mounting it to the window.

## First movement test

Before connecting the linkage, test the servo with the horn detached and confirm that it moves to the two commanded positions. Turn off power before fitting or repositioning the horn. Never force the shaft by hand.
