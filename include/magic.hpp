#include "main.h"
#include "globals.hpp"
#include <iostream>
#include <fstream>
#include <string>

inline pros::Motor driveOne(9, pros::MotorGearset::green);
inline pros::Motor driveTwo(10, pros::MotorGearset::green);


inline pros::MotorGroup leftMotors({-3, -2, -16}, pros::MotorGearset::blue);
inline pros::MotorGroup rightMotors({19, 20, 18}, pros::MotorGearset::blue);

inline std::ofstream fileO;

//("/usd/autonomous.txt", std::ios::in | std::ios::out | std::ios::app);

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