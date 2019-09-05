#!/bin/sh

g++ \
main.cpp \
./wheelDrive/twoWheelDrive.cpp \
./RoadControler/RoadControler.cpp \
./regulatorPD/regulatorPD.cpp \
./putVehicleOnLine/putVehicleOnLine.cpp \
./lineDetector/detector.cpp \
./encoder/encoder.cpp \
./dcMotor/DCmotor.cpp \
./controllerLookingForLine/controllerLookingForLine.cpp \
./controllerLineFollower/controllerLineFollower.cpp \
 -o main -std=c++17 -lwiringPi -lpthread
