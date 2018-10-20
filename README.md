### SFML Game
This is a top down shooter written in c++ using the SFML graphics library.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

## Prerequisites
-g++, a compiler.\
```$ sudo apt-get install g++```\
-SFML, the used c++ library.\
```$ sudo apt-get install libsfml-dev```

## Installing
Compile the main.cpp file into a main.o file using g++:\
```$ g++ -c main.cpp```\
Compile the main.o file into an executable called window using g++:\
```$ g++ main.o -o window -lsfml-graphics -lsfml-window -lsfml-system```\
To run the program do:
```$ ./window```

