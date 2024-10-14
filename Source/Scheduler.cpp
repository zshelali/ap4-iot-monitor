//
// Created by Ali on 23/09/2024.
//
#include "Scheduler.hpp"
#include "Server.hpp"
#include <random>
#include <thread>
#include <vector>

Scheduler::Scheduler() {};
Scheduler::~Scheduler(){};

Scheduler& Scheduler::operator=(const Scheduler& other) {
    if (this == &other) {
        return *this;
    }
    return *this;
}

void Scheduler::simulation(std::vector<std::shared_ptr<Sensor>>& sensors, Server& server){
    while (true) {
        // Update each sensor
        for (auto& sensor : sensors) {
            sensor->update();  // Update sensor data
            std::cout << *sensor << std::endl;
            server.fileWrite(*sensor);  // Send data to server
        }

        // Simulate break after the second update for demo purposes

        break;

    }
}

