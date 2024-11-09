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
#include <Thermometer.hpp>
#include <vector>

#include "Luxmeter.hpp"

//unique id variable
std::int32_t Sensor::sensor_next_id = 0; // Initialize the static variables

//default constructor
Sensor::Sensor() : sensor_id(sensor_next_id++) {
    sensor_data = 0.0f;
    default_type = "default";
    last_update_time = std::chrono::system_clock::now();
}

//copy constructor
Sensor::Sensor(const Sensor& other) : sensor_id(sensor_next_id++), default_type(other.default_type){} //copied object also gets a new Id !!!!

//assignment operator
Sensor& Sensor::operator=(const Sensor& other) {
    if (this !=&other) {
        this->default_type = other.default_type;
    }
    return *this;
}


Sensor::~Sensor() {}

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



std::string Sensor::getSensorData() {
    return std::to_string(this->sensor_data);
}


void Sensor::update() {
    // Get the current time
    const auto now = std::chrono::system_clock::now();

    // Calculate the time difference in seconds since the last update
    tpo = std::chrono::duration_cast<std::chrono::seconds>(now - last_update_time).count();

    // Debugging output to verify values
    // std::cout << "Current time: " << std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count()
    //           << " Last update time: " << std::chrono::duration_cast<std::chrono::seconds>(last_update_time.time_since_epoch()).count()
    //           << " Time since last update (tpo): " << tpo
    //           << " seconds, Duree: " << duree << std::endl;
    // Check if enough time has elapsed since the last execution
    if (tpo >= duree) {
        this->execute();               // Perform the sensor's task
        last_update_time = now;  // Reset the last update time only here
        //std::cout << "Executed sensor task. New sensor data: " << sensor_data << std::endl;
        std::cout << "😇😇😇😇😇😇" << std::endl;
    } else {
        std::cout << "Waiting for next update: " << (duree - tpo) << " seconds remaining" << std::endl;
    }
}




// void Sensor::execute() {
//     std::random_device random_device;
//     std::mt19937 generator(random_device());
//     std::uniform_int_distribution<> distribution(15, 30);
//     //generated random temperature between 15 and 30
//     int32_t temperature = distribution(generator);
//     std::cout << "Mesure de temps" << temperature <<std::endl;
// }

const std::int32_t Sensor::getId() {
    return sensor_id;
}

std::string Sensor::getDefault() {
    return this->default_type;
}

// void sensor":ëxecute
// auto now =std::chrono""system_clock::now();
// std::time_t end time_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//
// /*/
// cout << "mesure "
// s->mesure(this)
// /*/
