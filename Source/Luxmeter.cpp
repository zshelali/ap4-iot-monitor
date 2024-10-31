//
// Created by Ali on 14/10/2024.
//

#include "Luxmeter.hpp"
#include <random>

Luxmeter::Luxmeter() {
    default_type = "luxmeter";
    duree = 3;
}

Luxmeter::Luxmeter(const Luxmeter &other) {}

Luxmeter &Luxmeter::operator=(const Luxmeter &other) {}

Luxmeter::~Luxmeter() {}

void Luxmeter::execute() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> distrib2(0,1);
    this->light = (distrib2(gen) == 1); //returns true if random number is 1, else false
}
