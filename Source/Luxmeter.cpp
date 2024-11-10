//
// Created by Ali on 14/10/2024.
//

#include "Luxmeter.hpp"
#include <random>

Luxmeter::Luxmeter() {
    default_type = "Luxmeter";
    duree = 3;
}

Luxmeter::Luxmeter(const Luxmeter &other) {}

Luxmeter::Luxmeter(std::string name) {
    default_type = name;
    duree = 3;
}

std::string Luxmeter::getSensorData() {
    return std::to_string(this->light);
}


Luxmeter &Luxmeter::operator=(const Luxmeter &other) {}

Luxmeter::~Luxmeter() {}

void Luxmeter::execute() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> distrib2(0,1);
    this->light = (distrib2(gen)); //returns true if random number is 1, else false
    std::cout << "BOOL LIGHT " << this->light << std::endl;
}
