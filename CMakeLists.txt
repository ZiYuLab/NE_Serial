cmake_minimum_required(VERSION 3.26)
project(NESerial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./include)

add_executable(NESerial main.cpp
        src/NESerial.cpp
        include/NESerial.h
        main.cpp
        include/NEInit.h
        include/RmCRC.h
        src/RmCRC.cpp
        src/NERobotPosition.cpp
        include/NERobotPosition.h
)
