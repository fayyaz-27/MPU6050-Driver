# MPU6050 Driver for ESP32

Custom driver to interface the MPU6050 sensor with ESP32 via I2C Protocol using ESP-IDF.

## Features
- Initialize MPU6050 sensor and I2C Protocol
- Read raw accelerometer data (X, Y, Z axis)
- Read raw gyroscope data (X, Y, Z axis)
- Read temperature data from the sensor
- Simple API for easy integration

## Hardware Setup
- Connect MPU6050 SDA to ESP32 GPIO21 (or your I2C SDA pin)
- Connect MPU6050 SCL to ESP32 GPIO22 (or your I2C SCL pin)
- Power the MPU6050 with 3.3V and GND
