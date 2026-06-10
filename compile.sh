#! /bin/bash

g++ -O2 -o RaycasterAttempt -I ./include ./src/*.cpp ./src/UserSideSDL3/main.cpp  -lSDL3 