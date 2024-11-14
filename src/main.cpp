#include "main.h"
#include "magic.hpp"
#include "globals.hpp"
#include <string>

pros::MotorGroup leftMotors({11, 12}, pros::MotorGearset::green);
pros::MotorGroup rightMotors({-9, -4}, pros::MotorGearset::green);

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	//initO();
	initI();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	// while(true) {
	// 	readControllerData();
	// }

}

void opcontrol() {
	while(true) {
		//closeO();
		//writeControllerData();
		//drive();

		closeI();
		readControllerData();
		pros::delay(10);
	}
}