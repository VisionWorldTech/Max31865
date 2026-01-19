#include <SPI.h>
#include <Adafruit_MAX31865.h>

// ----- MAX31865 SPI Pins -----
#define MAX31865_CS   5   // Chip Select
#define MAX31865_MOSI 23
#define MAX31865_MISO 19
#define MAX31865_CLK  18

// Create MAX31865 object (software SPI for stability)
Adafruit_MAX31865 max31865 =
  Adafruit_MAX31865(MAX31865_CS, MAX31865_MOSI, MAX31865_MISO, MAX31865_CLK);

// ----- RTD Configuration -----
#define RTD_NOMINAL 100.0     // PT100 = 100, PT1000 = 1000
#define REF_RESISTOR 430.0    // PT100 = 430, PT1000 = 4300

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("MAX31865 Test Started");

  // Initialize MAX31865
  max31865.begin(MAX31865_2WIRE);  
  // Change if needed:
  // MAX31865_2WIRE
  // MAX31865_3WIRE
  // MAX31865_4WIRE
}

void loop() {
  // Read RTD resistance
  uint16_t rtd = max31865.readRTD();

  Serial.print("RTD raw value: ");
  Serial.println(rtd);

  float ratio = rtd;
  ratio /= 32768;

  Serial.print("Resistance: ");
  Serial.print(REF_RESISTOR * ratio, 3);
  Serial.println(" ohms");

  // Read temperature
  float temperature = max31865.temperature(RTD_NOMINAL, REF_RESISTOR);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Fault detection
  uint8_t fault = max31865.readFault();
  if (fault) {
    Serial.print("Fault detected: 0x");
    Serial.println(fault, HEX);

    if (fault & MAX31865_FAULT_HIGHTHRESH)
      Serial.println("RTD High Threshold");
    if (fault & MAX31865_FAULT_LOWTHRESH)
      Serial.println("RTD Low Threshold");
    if (fault & MAX31865_FAULT_REFINLOW)
      Serial.println("REFIN- < 0.85 x Bias");
    if (fault & MAX31865_FAULT_REFINHIGH)
      Serial.println("REFIN- > 0.85 x Bias");
    if (fault & MAX31865_FAULT_RTDINLOW)
      Serial.println("RTDIN- < 0.85 x Bias");
    if (fault & MAX31865_FAULT_OVUV)
      Serial.println("Under/Over Voltage");

    max31865.clearFault();
  }

  Serial.println("----------------------------");
  delay(2000);
}
