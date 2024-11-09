//
// Created by Ali on 14/10/2024.
//

#ifndef LUXMETER_HPP
#define LUXMETER_HPP
#include "Sensor.hpp"


class Luxmeter : public Sensor {
    friend Sensor;

public:
    Luxmeter();
    Luxmeter(std::string name);
    ~Luxmeter();
    Luxmeter(const Luxmeter& other);
    Luxmeter& operator=(const Luxmeter& other);

    void execute() override;

    std::string getSensorData() override;

private:
    bool light;
};



#endif //LUXMETER_HPP
