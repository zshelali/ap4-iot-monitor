//
// Created by Ali on 14/10/2024.
//

#ifndef THERMOMETER_HPP
#define THERMOMETER_HPP

#include "Sensor.hpp"

class Thermometer : public Sensor {
    friend Sensor;

public:
    Thermometer();
    Thermometer(const Thermometer& other);
    Thermometer& operator=(const Thermometer& other);
    ~Thermometer();


    void execute() override;

private:
    float temperature;

};



#endif //THERMOMETER_HPP
