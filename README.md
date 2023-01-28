# Seeed_SHT3X_SH110x_I2c
Seeed Studio XIAO RP2040 , SHT3# Temp + Hum, Adafruit SH110G LCD , I2C Bus

Example of a dual I2c address interprater.

4 Pin required on RP2040
  12 GND
  11 3v3 Or PIN 13 Via Power from USB-C Port
  4 SDA
  5 SCL
  
4 Pin required on SHT3X
  VIN = PIN 13 or 11
  GND = GND
  SCL/T = SDA (LCD)
  SDA/RH = SCL (LCD)
  
4 Pin required on LCD SH110G
  GND = GND
  VCC = VCC
  SCL = SCL (RP2040)
  SDA = SDA (RP2040)
  
  Power USB-C Port or 3V3 Pin(11) with 18650 LiPo single cell
