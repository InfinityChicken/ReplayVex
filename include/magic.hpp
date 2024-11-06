#include "main.h"
#include "globals.hpp"
#include <iostream>
#include <fstream>
#include <string>

inline pros::Motor driveOne(9, pros::MotorGearset::green);

inline std::ofstream file;//("/usd/autonomous.txt", std::ios::in | std::ios::out | std::ios::app);

extern bool active;
extern int count;

void write();
void init();
void close();
void smallTest();
void testSquared();