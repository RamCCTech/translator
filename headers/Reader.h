#pragma once
#include <vector>
#include <string>
#include "Triangle.h"

class Reader {
public:
    Reader();
    ~Reader();

    void readSTL(std::string filePath, Triangulation &triangulation);

};