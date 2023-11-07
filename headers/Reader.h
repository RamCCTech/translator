#pragma once
#include <vector>
#include <string>
#include "Triangle.h"
#include "Triangulation.h"
#include "TypeDef.h"

class Reader
{
public:
    Reader();
    ~Reader();

    void readOBJ(std::string filePath, Triangulation &triangulation);
    void readSTL(std::string filePath, Triangulation &triangulation);

private:
    void readOBJNormal(std::string line, PointList &normals);
    void readOBJFacet(std::string line, PointList &points, PointList &normals, Triangulation &triangulation);
    void readOBJVertex(std::string line, PointList &points);
    void readOBJName(std::string line,  Triangulation &triangulation);
};
