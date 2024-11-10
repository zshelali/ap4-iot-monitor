//
// Created by Ali on 23/09/2024.
//

#ifndef SERVER_HPP
#define SERVER_HPP

#include "Sensor.hpp"
#include <string>



class Sensor;

class Server {
    friend class Scheduler;
public:
    Server();
    Server(const Server& other);
    Server& operator=(const Server& other);
    ~Server();

    Server(const std::string& name);

    friend std::ostream& operator<<(std::ostream& os, const Server& server);

    //void consoleWrite(Sensor& sensor);

    int fileWrite(Sensor& sensor);

    std::string getName();

    //void measure(Sensor* sensor);

    static void readSensorFromTxt(const std::string& serverName);



private:
    std::string server_name;
};



#endif //SERVER_HPP
