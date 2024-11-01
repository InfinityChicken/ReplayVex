#include "main.h"
#include <cstdio>

FILE* write = fopen("/usd/autonomous.txt", "w");
FILE* read = fopen("/usd/autonomous.txt", "r");

void writeInit() {}

void write() {
    std::string dataLine = "";
    dataLine.append(driveOne.get_voltage() + " ");
    dataLine.append(driveTwo.get_voltage());
    
    fputs(dataLine, write);
}

void writeClose() {
    fclose(write);
}

void readInit() {}

void read() {
    
}