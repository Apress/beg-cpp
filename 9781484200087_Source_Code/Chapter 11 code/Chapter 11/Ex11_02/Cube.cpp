// Cube.cpp
#include <iostream>
#include "Cube.h"

Cube::Cube(double len) : side{len} { std::cout << "Cube constructor called." << std::endl; }

double Cube::volume()  { return side*side*side; }

bool Cube::compareVolume(Cube aCube) { return volume() > aCube.volume(); }
