#include "main.h"
#include "globals.hpp"
#include "magic.hpp"
#include <iostream>
#include <fstream>

bool active = true;

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
    if(pros::E_CONTROLLER_DIGITAL_DOWN && active) {
        file.close();
        active = false;
    }
}

void write() {
    if(active) {
        std::string dataLine = "";
        dataLine.append(driveOne.get_voltage() + " ");
        dataLine.append(driveTwo.get_voltage() + "\n");
        
        file << dataLine; //<< std::endl;
    }
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