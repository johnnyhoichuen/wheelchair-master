/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "Wire.h"
#include "WheelchairMaster.h"

// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 13

// #define I2C_WRITE_ADDR 0x18 // 0x18, not sure if 18 is correct here
// #define I2C_READ_ADDR 0x19 // 0x19, not sure if 18 is correct here
#define SLAVE_ADDR 0b0001100

int status = 0x00;

const int dataRow = 3;
const int dataCol = 2;

// // for Read Register
// // address, value to be read
// int data[dataRow][dataCol] = {
//     {SLAVE_ADDR, 0x28},
//     {SLAVE_ADDR, 0x00},
//     {SLAVE_ADDR, 0x00}};

// register address << 2 bits
int readAddr[11] = {
    0x28,
    0x2C,
    0x30,
    0x34,
    0x38,
    0x3C,
    0x40,
    0x44,
    0x48,
    0x4C,
    0x50};

// data1, data2, register << 2
//  * data1 = data[15:8]
//  * data2 = data[7:0]
int writeInfo[3][3] = {
    {0x80, 0x5C, 0x00},
    {0xE1, 0x80, 0x04},
    {0x01, 0xE5, 0x08}};

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Wire.begin(0b0001100); // start as slave with 7bit address
  Wire.begin(); // start as master
  Serial.begin(115200);

  // recall memory
  recallMemory(SLAVE_ADDR);
  exitMode(SLAVE_ADDR);

  // // read register
  // for (int i = 0; i < (int)sizeof(readAddr - 1); i++)
  // {
  //   readRegister(SLAVE_ADDR, readAddr[i]);
  //   exitMode(SLAVE_ADDR);
  // }
  // Serial.println("read register command issued");

  // // some operations and 2 delays (500/600ms)

  // // write register
  // for (int i = 0; i < (int)sizeof(writeInfo - 1); i++)
  // {

  //   writeRegister(SLAVE_ADDR, writeInfo[i][0], writeInfo[i][1], writeInfo[i][2]);
  //   exitMode(SLAVE_ADDR);
  // }
  // Serial.println("write register command issued");

  Serial.println("Setup completed");
}

void loop()
{
  // read measurement and print out
  Serial.println("reading data");

  // read data
  

  // visual clue to check if the loop is running
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void readData() {

}

// /***
//  * data1 = data[15:8]
//  * data2 = data[7:0]
//  */
// void setRegisterResponse(int address, int data1, int data2){
//   Wire.beginTransmission(address);

//   // ******not sure about the write sequence, need to double check

//   Wire.write(data1);
//   Wire.write(data2);
//   Wire.endTransmission();
// }