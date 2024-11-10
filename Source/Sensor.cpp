//
// Created by Ali on 23/09/2024.
//

#include "Sensor.hpp"

#include "Server.hpp"

#include <random>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


//unique id variable
std::int32_t Sensor::sensor_next_id = 0;

Sensor::Sensor() : sensor_id(sensor_next_id++) {
    sensor_data = 0.0f;
    default_type = "default";
    last_update_time = std::chrono::system_clock::now();
}

Sensor::Sensor(const Sensor& other) : sensor_id(sensor_next_id++), default_type(other.default_type){} //copied object also gets a new Id !!!!

Sensor& Sensor::operator=(const Sensor& other) {
    if (this !=&other) {
        this->default_type = other.default_type;
    }
    return *this;
}


Sensor::~Sensor() {}


std::string Sensor::getTime() {
    std::time_t time = std::chrono::system_clock::to_time_t(this->last_update_time);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d/%H:%M:%S");  // Format: YYYY-MM-DD HH:MM:SS
    return oss.str();
}

//Manual sensor, just for testing (default type)
Sensor::Sensor(const std::string &n) : sensor_id(sensor_next_id++) {
    this->default_type = n;
}


std::ostream& operator<<(std::ostream& os, const Sensor& sensor) {
    os << "Sensor ID: " << sensor.sensor_id << "\n";
    os << "Default Type: " << sensor.default_type << "\n";
    os << "Sensor Data: " << sensor.sensor_data << "\n";
    os << "TPO: " << sensor.tpo << "\n";
    os << "Duree: " << sensor.duree << "\n";
    return os;
}




void Sensor::update() {
    const auto now = std::chrono::system_clock::now();
    tpo = std::chrono::duration_cast<std::chrono::seconds>(now - last_update_time).count();
    if (tpo >= duree) {
        this->execute();
        last_update_time = now;
        updated = true;
        std::cout << "😇😇😇😇😇😇" << std::endl;
    } else {
        std::cout << "Waiting for next update for : " << this->getDefault() << ">>" << (duree - tpo) << " seconds remaining" << std::endl;
    }
}


const std::int32_t Sensor::getId() {
    return sensor_id;
}

const std::string Sensor::getDefault() {
    return this->default_type;
}

