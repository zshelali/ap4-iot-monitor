//
// Created by Ali on 10/11/2024.
//

#ifndef DECIBELMETER_HPP
#define DECIBELMETER_HPP

#include "Sensor.hpp"

class Decibelmeter : public Sensor {
    friend Sensor;

public:
    Decibelmeter();
    Decibelmeter(std::string name);
    Decibelmeter(const Decibelmeter& other);
    Decibelmeter& operator=(const Decibelmeter& other);
    ~Decibelmeter();

    void execute() override;
    std::string getSensorData() override;

private:
    int sound;

};
#endif //DECIBELMETER_HPP
