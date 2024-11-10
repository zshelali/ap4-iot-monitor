//
// Created by Ali on 23/09/2024.
//

#include "Server.hpp"

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include "Sensor.hpp"
#include <algorithm>

Server::Server() : server_name("Server") {};

Server::~Server(){};

Server::Server(const std::string& name) {
    this->server_name = name;
}


std::ostream& operator<<(std::ostream& os, const Server& server) {
    if (!server.server_name.empty()){
        os << "Server Name: " << server.server_name << std::endl; //printed if NOT empty
    }
    else {
        os << "Server does not have a name : I give up." << server.server_name << std::endl;
    }
    return os;
};



std::string Server::getName() {
    return this->server_name;
}



int Server::fileWrite(Sensor& sensor) {
    std::string path = "";
    std::string to_stringData = sensor.getSensorData();
    std::string content =
        std::to_string(sensor.getId()) + ";"
        + sensor.getDefault() + ";"
        + to_stringData + ";"
        + sensor.getTime()
        + "\n";

    if (!this->getName().empty()) {
        path = "../FileLogs/" + this->getName() + ".csv";
    } else {
        path = "../FileLogs/UnnamedServer.csv";
    }
    std::ofstream outFile(path, std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Could not open or create file: " << path << std::endl;
        return 1;
    }
    if (outFile.tellp() == 0) {
        outFile << "ID;Type;Data;TimeUpdate\n";
    }
    outFile << content;
    outFile.close();
    std::cout << "Content successfully written in file: " << path << std::endl;

    return 0;
}

void Server::readSensorFromTxt(const std::string& serverName) {
    std::string path = "../FileLogs/" + (serverName.empty() ? "UnnamedServer" : serverName) + ".csv";
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        std::stringstream ss(line);
        std::string id_str, type, data_str, time_update;
        int id;
        float data;

        std::getline(ss, id_str, ';');
        std::getline(ss, type, ';');
        std::getline(ss, data_str, ';');
        std::getline(ss, time_update, ';');

        try {
            id = std::stoi(id_str);
            data = std::stof(data_str);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        std::cout << "ID: " << id
                  << ", Type: " << type
                  << ", Data: " << data
                  << ", TimeUpdate: " << time_update <<std::endl;

    }

    file.close();
}