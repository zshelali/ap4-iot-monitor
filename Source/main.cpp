#include <iostream>
#include <string>
#include <vector>

#include "Decibelmeter.hpp"
#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"
#include "Thermometer.hpp"
#include "Luxmeter.hpp"

using namespace std;

int main() {
    std::vector<std::shared_ptr<Sensor>> sensors;
    Server server("MyServer");
    std::string serverName = server.getName();

    Server::readSensorFromTxt(serverName);
    for (int i = 0; i < 2; i++) {
        sensors.push_back(std::make_shared<Thermometer>());
        sensors.push_back(std::make_shared<Luxmeter>());
        sensors.push_back(std::make_shared<Decibelmeter>());
    }

    Scheduler::simulation(sensors, server);


    return 0;
}