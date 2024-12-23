#include "main.h"
#include "globals.hpp"
#include "magic.hpp"
#include <iostream>
#include <fstream>
#include <string>

bool active = true;
// int count = 1;

void initO() {
    fileO.open("/usd/autonomous.txt");

    if(!fileO) {
        controller.set_text(0, 0, "failed to open");
        active = false;
    }
    else{
        controller.set_text(0, 0, "opened");
        active = true;
    }
}

void initI() {
    fileI.open("/usd/autonomous.txt");

    if(!fileI) {
        controller.set_text(0, 0, "failed to open");
        active = false;
    }
    else{
        controller.set_text(0, 0, "opened");
        active = true;
    }
}

void closeO() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) && active) {
        fileO.flush();
        controller.set_text(0, 0, "WAIT FIVE SECONDS!!!");
        pros::delay(5000);
        fileO.close();
        active = false;
        controller.set_text(0, 0, "file closed                           ");
    }
}

void closeI() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) && active) {
        fileI.close();
        active = false;
        controller.set_text(0, 0, "file closed                           ");
    }
}

void write() {
    if(active) {
        std::string dataLine = "";
        dataLine.append(std::to_string(leftMotors.get_voltage()) + " ");
        dataLine.append(std::to_string(rightMotors.get_voltage()) + "\n");
        
        fileO << dataLine; //<< std::endl;
        
        fileO.flush();
    }
}

void writeControllerData() {
    if(active) {
        std::string dataLine = "";
        dataLine.append(std::to_string(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) + " ");
        dataLine.append(std::to_string(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)) + "\n");

        fileO << dataLine;
        
        fileO.flush();
    }
}

void read() {
    if(active) {
        int voltages[2];
        
        for (int i=0; i<2; i++) {
            fileI >> voltages[i];
        }

        leftMotors.move_voltage(voltages[0]);
        rightMotors.move_voltage(voltages[1]);

        // driveTwo.move_voltage(voltages[1]);
    }
    
    /* if(active) {
        int voltage;
        fileI >> voltage;
        
        // double voltages[2];
        // for (int i=0; i<2; i++) {
        //     file >> voltages[i];
        // }

        driveOne.move_voltage(voltage);

        // driveTwo.move_voltage(voltages[1]);
    } */
}

void readControllerData() {
    if(active) {
        double leftInput;
        double rightInput;

        fileI >> leftInput;
        fileI >> rightInput;

        leftMotors.move_velocity((leftInput));
        rightMotors.move_velocity((leftInput));
    }
}

void runMotors() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
		driveOne.move_voltage(12000);
    } else {
		driveOne.move_voltage(0);
    }

    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        driveTwo.move_voltage(12000);
    } else {
        driveTwo.move_voltage(0);
    }
}

void driveBasic() {
    leftMotors.move_velocity(
        (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)));
    rightMotors.move_velocity(
        (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)));
}

void writeSubsystems() {
    if(active) {
        std::string dataLine = "";

        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A))


        fileO << dataLine;
        
        fileO.flush();
    }

}

void writePose() {
   lemlib::Pose pose = chassis.getPose();

   dataLine.append(std::to_string(pose.x) + ", ");
   dataLine.append(std::to_string(pose.y) + ", ");
   dataLine.append(std::to_string(pose.theta) + "\n");
}

void readPose() {
    
}