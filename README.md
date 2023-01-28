# Seeed_SHT3X_SH110x_I2c
Seeed Studio XIAO RP2040 , SHT3# Temp + Hum, Adafruit SH110G LCD , I2C Bus

Example of a dual I2c address interprater.

4 Pin required on RP2040
  2 GND
  3 3v3 Or PIN 1 Via Power from USB-C Port
  12 SDA
  13 SCL
  
4 Pin required on SHT3X
  VIN = PIN 3
  GND = GND
  SCL/T = SDA (LCD)
  SDA/RH = SCL (LCD)
  
4 Pin required on LCD SH110G
  GND = GND
  VCC = VCC
  SCL = SCL (RP2040)
  SDA = SDA (RP2040)
  
  Power USB-C Port or 3V3 Pin with 18650 LiPo single cell
