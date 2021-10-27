#include "Arduino.h"
// #include "Wire.h"
#include "WheelchairMaster.h"

// 0011 zyxt
// eg. x & y axis => 0110 or 0x6
void startSingleMeasurementMode(int address, int axis)
{
    Wire.beginTransmission(address);
    Wire.write(0x30 + axis);
    Wire.endTransmission();

    Wire.requestFrom(address, 1);
}

// for now it's XY axis only (TXYZ)
void readMeasurement(int address, int axis)
{
    startSingleMeasurementMode(address, axis);

    Wire.beginTransmission(address);
    Wire.write(0x40 + axis);
    Wire.endTransmission();

    /*
    * somehow 5 does not work & has to be 10
    * >10 -> get FF instead (invalid)
    */
    // Wire.requestFrom(address, 10);
    Wire.requestFrom(address, 5);
}

void readRegister(int address, int targetAddr)
{
    Wire.beginTransmission(address);
    Wire.write(0x50);
    Wire.write(targetAddr);
    Wire.endTransmission();

    Wire.requestFrom(address, 3);
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

    Wire.requestFrom(address, 1);
}

void exitMode(int address)
{
    Wire.beginTransmission(address);
    Wire.write(0x80);
    Wire.endTransmission();

    Wire.requestFrom(address, 1);
}

void recallMemory(int address)
{
    Wire.beginTransmission(address);
    Wire.write(0xD0);
    Wire.endTransmission();

    Wire.requestFrom(address, 1);
}
