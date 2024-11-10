#include <random>
#include "Decibelmeter.hpp"
#include <iostream>

Decibelmeter::Decibelmeter() {
    default_type = "Decibelmeter";
    duree = 1;
};


Decibelmeter::Decibelmeter(std::string name) {
    default_type = name;
    duree = 1;
}

std::string Decibelmeter::getSensorData() {
    return std::to_string(this->sound);
}

Decibelmeter::Decibelmeter(const Decibelmeter &other) {
}

Decibelmeter &Decibelmeter::operator=(const Decibelmeter &other) {}

Decibelmeter::~Decibelmeter() {
}



void Decibelmeter::execute() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> distrib3(0,100);
    this->sound = distrib3(gen);
    std::cout << "SOUND : " << this->sound << std::endl;

}