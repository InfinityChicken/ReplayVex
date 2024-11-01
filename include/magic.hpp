#include "main.h"
#include "globals.hpp"
#include <iostream>
#include <fstream>

inline pros::Motor driveOne(9, pros::MotorGearset::green);
inline pros::Motor driveTwo(9, pros::MotorGearset::green);

inline std::fstream file("/usd/autonomous.txt", std::ios::in | std::ios::out | std::ios::app);

extern bool active;

void write();
void read();
void init();
void close();