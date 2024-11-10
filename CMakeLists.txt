cmake_minimum_required(VERSION 3.24)
project(ap4-iot-monitor)

set(CMAKE_CXX_STANDARD 17)

add_executable(ap4-iot-monitor
        Source/main.cpp
        Source/Scheduler.cpp
        Source/Sensor.cpp
        Source/Server.cpp
        Source/Thermometer.cpp
        Source/Luxmeter.cpp
        Source/Decibelmeter.cpp


)

target_include_directories(ap4-iot-monitor PUBLIC ${PROJECT_SOURCE_DIR}/Header
                                             ${PROJECT_SOURCE_DIR}/Source
)