// #include "Arduino.h"
// #include "Wire.h"
#include "WheelchairMaster.h"

// 0011 zyxt
// eg. x & y axis => 0110 or 0x6
void startSingleMeasurementMode(int address, int axis)
{
    Wire.beginTransmission(address);
    Wire.write(0x30 + axis);
    Wire.endTransmission();
}

// for now it's XY axis only (TXYZ)
void readMeasurement(int address, int targetAddr, int axis)
{
    startSingleMeasurementMode(address, axis);

    Wire.beginTransmission(address);
    Wire.write(0x40 + axis);
    Wire.write(targetAddr);
    Wire.endTransmission();

    //   while (Wire.available()) {
    //     char c = Wire.read();
    //     Serial.print(c);
    //   }
}

void readRegister(int address, int targetAddr)
{
    Wire.beginTransmission(address);
    Wire.write(0x50);
    Wire.write(targetAddr);
    Wire.endTransmission();

    //   while (Wire.available()) {
    //     char c = Wire.read();
    //     Serial.print(c);
    //   }
}

// data1 = data[15:8]
// data2 = data[7:0]
// targetAddr should be << 2 bits
void writeRegister(int address, int data1, int data2, int targetAddr)
{
    Wire.beginTransmission(address);
    Wire.write(0x60);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(targetAddr);
    Wire.endTransmission();

    //   while (Wire.available()) {
    //     char c = Wire.read();
    //     Serial.print(c);
    //   }
}

void exitMode(int address)
{
    Wire.beginTransmission(address);
    Wire.write(0x80);
    Wire.endTransmission();

    //   while (Wire.available()) {
    //     char c = Wire.read();
    //     Serial.print(c);
    //   }
}

void recallMemory(int address)
{
    Wire.beginTransmission(address);
    Wire.write(0xD0);
    Wire.endTransmission();
}
