//
// Created by Ali on 14/10/2024.
//

#include "Thermometer.hpp"
#include <random>

Thermometer::Thermometer() {
    default_type = "thermometer";
    duree = 1;
};

Thermometer::Thermometer(std::string name) {
    default_type = name;
    duree = 1;
}

Thermometer::Thermometer(const Thermometer &other) {
}

Thermometer &Thermometer::operator=(const Thermometer &other) {}

Thermometer::~Thermometer() {
}

void Thermometer::execute() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> distrib3(0,100);
    this->sensor_data = distrib3(gen);
    std::cout << "TEMP 🌡️🌡️🥵: " << this->sensor_data << std::endl;

}