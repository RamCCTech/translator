#pragma once
#include <string>
#include "Triangulation.h"
#include "headers/TypeDef.h"

class Reader
{
public:
    Reader();
    ~Reader();

    void readOBJ(std::string filePath, Triangulation &triangulation);

private:
    void readOBJNormal(std::string line, PointList &normals);
    void readOBJFacet(std::string line, PointList &points, PointList &normals, Triangulation &triangulation);
    void readOBJVertex(std::string line, PointList &points);
};
