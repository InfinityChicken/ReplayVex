#include "main.h"
#include "magic.hpp"
#include "globals.hpp"
#include <string>

// pros::MotorGroup leftMotors({-3, -2, -16}, pros::MotorGearset::blue);
// pros::MotorGroup rightMotors({19, 20, 18}, pros::MotorGearset::blue);

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
	// initO();
	initI();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while(true) {
		closeO();
		write();

		closeI();
		read();
		pros::delay(10);
	}
}