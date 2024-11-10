//
// Created by Ali on 23/09/2024.
//
#include "Scheduler.hpp"
#include "Server.hpp"
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
        for (auto & sensor : sensors) {
            sensor->update();
            if (sensor->updated) {server.fileWrite(*sensor);}
            sensor->updated = false;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
}

