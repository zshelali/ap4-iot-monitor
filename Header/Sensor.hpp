//
// Created by Ali on 23/09/2024.
//

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
// #include "Server.hpp"
#include <string>

/*
 * Warning : Every single sensor has a unique id, even copied ones
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

    /* /////////////////
     * Imposed functions
     */
    void update(); //virtual ??
    void virtual execute();


    const std::int32_t getId();
    std::string getDefault();
    float virtual getSensorData();

protected:
    /* //////////////////
     * Imposed attributes
     */
    std::int32_t sensor_id, tpo, duree;
    std::string default_type;
    float static sensor_data;
    Server* pserver;

    /* /////////////////
     * Custom Attributes
     */
    static std::int32_t sensor_next_id;
    std::chrono::time_point<std::chrono::system_clock> last_update_time;  // Time of the last update


};

#endif // SENSOR_HPP
