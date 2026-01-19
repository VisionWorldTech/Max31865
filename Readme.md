# ESP32 + MAX31865 (PT100 RTD) Interface

This repository demonstrates how to interface a **MAX31865 RTD-to-Digital Converter** with an **ESP32** to measure temperature using **PT100 RTD sensors**.

The setup is suitable for **industrial-grade temperature measurement** with high accuracy and fault detection.

---

## 📌 About MAX31865

The **MAX31865** is a precision RTD (Resistance Temperature Detector) interface IC that:
- Measures RTD resistance accurately
- Converts it to digital data
- Communicates via **SPI**
- Supports **PT100 and PT1000**
- Works with **2-wire, 3-wire, and 4-wire RTDs**
- Includes **fault detection** (open, short, under/over voltage)

Typical temperature range (PT100):
- **–200°C to +850°C**

---

## 🔧 Hardware Used

- ESP32 Dev Module
- MAX31865 RTD Amplifier Module
- PT100 RTD Sensor (**2-wire used in this project**)
- Jumper wires
- 3.3V Power Supply

---

## 🔌 ESP32 ↔ MAX31865 Wiring (SPI)

| MAX31865 Pin | ESP32 Pin | Description |
|-------------|----------|-------------|
| VCC / VIN | 3.3V | Power (⚠️ 3.3V only) |
| GND | GND | Ground |
| SCK / CLK | GPIO 18 | SPI Clock |
| SDI / MOSI | GPIO 23 | SPI MOSI |
| SDO / MISO | GPIO 19 | SPI MISO |
| CS / SS | GPIO 5 | Chip Select |
| RDY | Not Connected | Optional interrupt |

---

## 🌡️ RTD Sensor Connections

MAX31865 RTD terminals are usually labeled as:

