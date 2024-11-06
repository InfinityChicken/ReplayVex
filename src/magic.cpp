#include "main.h"
#include "globals.hpp"
#include "magic.hpp"
#include <iostream>
#include <fstream>
#include <string>

bool active = true;
// int count = 1;

void init() {
    //std::ofstream file("/usd/autonomous.txt");
    file.open("/usd/autonomous.txt");
    if(!file) {
        controller.set_text(0, 0, "failed to open");
        active = false;
    }
    else{
        controller.set_text(0, 0, "opened");
        active = true;
    }
}

void close() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && active) {
        file.flush();
        controller.set_text(0, 0, "WAIT FIVE SECONDS!!!");
        pros::delay (5000);
        file.close();
        active = false;
        controller.set_text(0, 0, "file closed                     ");
    }
}

void write() {
    if(active) {
        std::string dataLine = "";
        dataLine.append(std::to_string(driveOne.get_voltage()) + "\n");
        // dataLine.append(driveTwo.get_voltage() + "\n");
        
        file << dataLine; //<< std::endl;
        
        file.flush();
    }
}

void smallTest() {
    file << "PLEASE FOR THE LOVE OF GOD";
    controller.set_text(0, 0, "hooray");
    pros::delay(3000);
    file.flush();
    controller.set_text(0, 0, "flushed");
    pros::delay(3000);
    file.close();
    controller.set_text(0, 0, "file closed");
    pros::delay(3000);
}

void testSquared() {
    std::string dataLine = "";
    dataLine.append(std::to_string(driveOne.get_voltage()) + "\n");

}

/*void read() {
    if(active) {
        double voltages[2];
        for (int i=0; i<2; i++) {
            file >> voltages[i];
        }
        driveOne.move_voltage(voltages[0]);
        driveTwo.move_voltage(voltages[1]);
    }
}*/