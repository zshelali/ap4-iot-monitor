//
// Created by Ali on 23/09/2024.
//


#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "Sensor.hpp"
#include <vector>
#include <memory>



class Scheduler {
    friend class Sensor;
public:
    Scheduler();
    Scheduler(const Scheduler& other); //not implemented
    Scheduler& operator=(const Scheduler& other);
    ~Scheduler();

    // std::vector<Sensor>& fetchSensor();
    // void addServer();
    void static simulation(std::vector<std::shared_ptr<Sensor>>& sensors, Server& server);



};
#endif //SCHEDULER_HPP
