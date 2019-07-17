#!/bin/sh

g++ main.cpp ./wheelDrive/twoWheelDrive.cpp ./dcMotor/DCmotor.cpp ./encoder/encoder.cpp \
./regulatorPD/regulatorPD.cpp \
 lineDetector/detector.cpp \
 controllerLineFollower/controllerLineFollower.h \
 controllerLookingForLine/controllerLookingForLine.h\
 -o main -std=c++17 -lwiringPi -lpthread
