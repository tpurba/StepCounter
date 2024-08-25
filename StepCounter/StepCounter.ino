#include <Arduino.h>
// #include "LCD_Test.h"
#include "DEV_Config.h"
#include "QMI8658.h"
#include <Wire.h>

#define QMI8658_ADDR 0x6B  // I2C address of the QMI8658 sensor

// Register Addresses (example addresses, adjust based on your setup)
#define CTRL7 0x1C
#define CTRL8 0x1D
#define CTRL9 0x1E
#define STATUS1 0x1F
#define STEP_CNT_LOW 0x30
#define STEP_CNT_MIDL 0x31
#define STEP_CNT_HIGH 0x32
#define CAL1_L 0x21
#define CAL1_H 0x22
#define CAL2_L 0x23
#define CAL2_H 0x24
#define CAL3_L 0x25
#define CAL3_H 0x26
#define CAL4_H 0x28

void writeRegister(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(QMI8658_ADDR);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

uint8_t readRegister(uint8_t reg) {
  Wire.beginTransmission(QMI8658_ADDR);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(QMI8658_ADDR, 1);
  return Wire.read();
}

void setup() {
  Serial.begin(115200);
  
  if (DEV_Module_Init() != 0)//initializes GPIO pins 
    Serial.println("GPIO Init Fail!");
  else
    Serial.println("GPIO Init successful!");
#if 1
  float acc[3], gyro[3];
  unsigned int tim_count = 0;
  uint16_t result;
  QMI8658_init();
  while (true)
  {
    result = DEC_ADC_Read();
    QMI8658_read_xyz(acc, gyro, &tim_count);
    Serial.println("ACC_X = " );
    Serial.println(acc[0]);
    Serial.println("ACC_Y = " );
    Serial.println(acc[1]);
    Serial.println("ACC_Z = " );
    Serial.println(acc[2]);
    Serial.println("GYR_X = " );
    Serial.println(gyro[0]);
    Serial.println("GYR_Y = " );
    Serial.println(gyro[1]);
    Serial.println("GYR_Z = " );
    Serial.println(gyro[2]);
  }
#endif
}

void loop() {
}
void init_Pedometer(){

}
