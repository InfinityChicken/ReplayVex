#include "main.h"
#include "globals.hpp"
#include <iostream>
#include <fstream>
#include <string>

inline pros::Motor driveOne(9, pros::MotorGearset::green);
inline pros::Motor driveTwo(10, pros::MotorGearset::green);

extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

inline std::ofstream fileO;
inline std::ifstream fileI;

extern bool active;
extern int count;

void write();
void read();
void initO();
void initI();
void closeO();
void closeI();

void runMotors();
void driveBasic();
void writeControllerData();
void readControllerData();

void writePose();
void readPose();