//
// Created by Ali on 23/09/2024.
//

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
// #include "Server.hpp"
#include <string>
#include <random>


/*
 * Warning : Every single sensor has a unique id, even copied ones !!
 */

class Server;


class Sensor
{
 friend class Scheduler;
 friend std::ostream& operator<<(std::ostream& os, const Sensor& sensor);
public:
    Sensor();
    Sensor(const Sensor& other);
    Sensor& operator=(const Sensor& other);
    virtual ~Sensor();

    /*
     * Constructor to edit the default type (test purposes)
     */
    Sensor(const std::string &n);


    void update(); //not virtual
    void virtual execute() = 0;


    const std::int32_t getId();
    const std::string getDefault();
    std::string virtual getSensorData() = 0;
    std::string getTime();

protected:

    std::uint32_t sensor_id, duree;
    long long tpo;
    std::string default_type;
    float sensor_data;
    Server* pserver;


    static std::int32_t sensor_next_id;
    static std::random_device rd;
    std::chrono::time_point<std::chrono::system_clock> last_update_time;
    bool updated = false;


};

#endif // SENSOR_HPP
