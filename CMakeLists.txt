cmake_minimum_required(VERSION 3.29)
project(ProjetTP_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetTP_4
        Source/main.cpp
        Source/Scheduler.cpp
        Source/Sensor.cpp
        Source/Server.cpp
        Source/Thermometer.cpp
        Source/Luxmeter.cpp


)

target_include_directories(ProjetTP_4 PUBLIC ${PROJECT_SOURCE_DIR}/Header
                                             ${PROJECT_SOURCE_DIR}/Source
)