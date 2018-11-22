#!/bin/bash

set -e

mkdir -p out

g++ -Iinclude -c src/main.cpp -o out/main.o
g++ -Iinclude -c src/GameEngine.cpp -o out/GameEngine.o

g++ out/main.o out/GameEngine.o \
    -o counting \
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
