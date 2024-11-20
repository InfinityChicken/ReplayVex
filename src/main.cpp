#include "main.h"
#include "magic.hpp"
#include "globals.hpp"
#include <string>

pros::MotorGroup leftMotors({11, 12}, pros::MotorGearset::green);
pros::MotorGroup rightMotors({-9, -4}, pros::MotorGearset::green);

lemlib::Drivetrain drivetrain(&leftMotors, &rightMotors, 10, lemlib::Omniwheel::NEW_325, 450, 6);

lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);



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
	chassis.calibrate();
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
		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with curvature drive

        chassis.arcade(leftY, rightX * 0.8);
		pros::delay(10);
	}
}

void readPose() {

}