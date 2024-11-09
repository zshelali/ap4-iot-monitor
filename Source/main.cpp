#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"
#include "Thermometer.hpp"
#include "Luxmeter.hpp"

using namespace std;

int main() {
    std::vector<std::shared_ptr<Sensor>> sensors;  // Vector of shared pointers to Sensor objects
    Server server("MyServer");
    std::string serverName = server.getName();

    Server::readSensorFromTxt(serverName);
    // Add 3 Thermometers and 3 Luxmeters objects to the sensors vector
    for (int i = 0; i < 3; i++) {
        sensors.push_back(std::make_shared<Thermometer>());
        sensors.push_back(std::make_shared<Luxmeter>());
    }

    // Simulate the sensor updates
    Scheduler::simulation(sensors, server);


    return 0;
}