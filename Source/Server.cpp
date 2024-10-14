//
// Created by Ali on 23/09/2024.
//

#include "Server.hpp"

#include <iostream>
#include <ostream>
#include <fstream>
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
    std::string to_stringData = std::to_string(sensor.getSensorData());
    std::string content =
        std::to_string(sensor.getId()) + ";"
        + sensor.getDefault() + ";"
        + to_stringData + ";"
        + "\n";

    // Determine the file path based on whether the server has a name
    if (!this->getName().empty()) {
        path = "../FileLogs/" + this->getName() + ".txt";
    } else {
        path = "../FileLogs/UnnamedServer.txt";
    }

    // Open file in append mode, which creates the file if it doesn't exist
    std::ofstream outFile(path, std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Could not open or create file: " << path << std::endl;
        return 1;
    }

    // Write header if the file was just created and is empty
    if (outFile.tellp() == 0) {  // Check if the file is empty
        outFile << "ID;Type;Data;\n";  // Add the header once
    }

    // Append sensor data to the file
    outFile << content;

    outFile.close();

    std::cout << "Content successfully written in file: " << path << std::endl;

    return 0;
}
