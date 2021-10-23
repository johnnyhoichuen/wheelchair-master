#pragma once

#include "Wire.h"

void startSingleMeasurementMode(int address, int axis);
void readMeasurement(int address, int targetAddr, int axis);
void readRegister(int address, int targetAddr);
void writeRegister(int address, int data1, int data2, int targetAddr);
void exitMode(int address);
void recallMemory(int address);